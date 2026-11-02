#!/usr/bin/env python3
"""Run the exercises' tests and update the Status columns in the README files.

Any README.md in the repo can track exercises in its tables. A row with a ⬜
or ✅ that links to a .cpp file (a LeetCode problem) or to a folder with a
Makefile (a debugging exercise) gets ✅ when all of the exercise's tests pass,
and ⬜ otherwise, so it goes back to ⬜ if it stops passing.

  - A LeetCode problem is compiled and run with a time limit, so a solution
    that is correct but too slow doesn't count.
  - A debugging exercise runs `make check`: its visible and hidden tests.

A row that links to a folder of LeetCode problems and has a count like `3/5`
is a progress summary: the script keeps the count up to date.

Usage:
    ./update_status.py                  # everything, with a one-line summary per folder
    ./update_status.py hashing tree     # only exercises whose path contains these words
    ./update_status.py -v               # everything, one line per exercise
    ./update_status.py --time-limit 2   # allow 2 s per LeetCode problem (default 0.5)
"""

import argparse
import os
import re
import shutil
import signal
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent
BUILD_DIR = ROOT / ".build"  # compiled LeetCode tests, reused until their .cpp file changes
COMPILE = ["g++", "-std=c++17", "-O2", "-Wall"]
JOBS = min(16, os.cpu_count() or 1)
EXERCISE_TIMEOUT = 120  # seconds for a debugging exercise's `make check`, build included
DONE, TODO = "✅", "⬜"

# A row's first local link: [01](01_x.cpp) or [01](debugging/01_x/)
TARGET_LINK = re.compile(r"\]\(([^()\s:#]+?(?:\.cpp|/))\)")
COUNT_CELL = re.compile(r"\|\s*\d+/\d+\s*\|")  # a summary row's "3/5" cell
SUMMARY = re.compile(r"(\d+)/(\d+) tests passed")  # last line of every test run
COMPILE_ERROR = re.compile(r"^(.+?):(\d+):\d+: (?:fatal )?error: (.*)$")


def rel(path):
    return path.relative_to(ROOT).as_posix()


def is_exercise_folder(target):
    return target.suffix != ".cpp" and (target / "Makefile").is_file()


def binary_for(src):
    """leetcode/01_hashing/01_x.cpp -> .build/leetcode__01_hashing__01_x"""
    return BUILD_DIR / "__".join(src.relative_to(ROOT).with_suffix("").parts)


def first_error(stderr, in_file=None):
    """The first compiler error as (file, line, message), optionally only one in in_file."""
    for line in stderr.splitlines():
        error = COMPILE_ERROR.match(line)
        if error and (in_file is None or error[1] == in_file):
            return error[1], error[2], error[3]
    return None


def build(src):
    """Compile a LeetCode problem if needed. Returns None on success, otherwise what went wrong."""
    if not src.is_file():
        return "file not found"
    exe = binary_for(src)
    if exe.exists() and exe.stat().st_mtime_ns > src.stat().st_mtime_ns:
        return None  # already built from the current version of the file
    exe.unlink(missing_ok=True)  # so a failed build can't leave an old, passing binary behind
    result = subprocess.run([*COMPILE, str(src), "-o", str(exe)],
                            capture_output=True, text=True, errors="replace")
    if result.returncode == 0:
        return None
    error = first_error(result.stderr, in_file=str(src))
    if error:
        return f"compile error, line {error[1]}: {error[2]}"
    return "compile error (build the file by hand to see it)"


def run_problem(exe, time_limit):
    """Run a compiled LeetCode problem. Returns (all tests passed, one-line summary)."""
    start = time.perf_counter()
    try:
        result = subprocess.run([str(exe)], capture_output=True, text=True,
                                errors="replace", timeout=time_limit)
    except subprocess.TimeoutExpired:
        return False, f"too slow: stopped after {time_limit:g} s"
    seconds = time.perf_counter() - start
    if result.returncode < 0:
        try:
            name = signal.Signals(-result.returncode).name
        except ValueError:
            name = f"signal {-result.returncode}"
        return False, f"crashed ({name})"
    if result.returncode != 0:
        return False, f"exited with code {result.returncode}"
    counts = SUMMARY.findall(result.stdout)
    if not counts:
        return False, "no test summary printed"
    passed, total = map(int, counts[-1])
    ms = round(seconds * 1000)
    took = f"{ms} ms" if ms < 1000 else f"{seconds:.2f} s"
    return total > 0 and passed == total, f"{passed}/{total} tests passed in {took}"


def run_exercise(folder):
    """Run a debugging exercise's visible and hidden tests. Returns (all passed, summary)."""
    try:
        result = subprocess.run(["make", "-s", f"-j{JOBS}", "check"], cwd=folder,
                                capture_output=True, text=True, errors="replace",
                                timeout=EXERCISE_TIMEOUT)
    except subprocess.TimeoutExpired:
        return False, f"stopped after {EXERCISE_TIMEOUT} s: an infinite loop?"
    counts = SUMMARY.findall(result.stdout)
    if counts:
        passed, total = map(int, counts[-1])
        return total > 0 and passed == total, f"{passed}/{total} tests passed, hidden ones included"
    error = first_error(result.stderr)
    if error:
        return False, f"build error, {error[0]} line {error[1]}: {error[2]}"
    return False, "build failed or the tests crashed (run `make check` in the folder to see why)"


def find_readmes():
    skip = {"build", "node_modules"}
    readmes = [ROOT / "README.md"] if (ROOT / "README.md").is_file() else []
    for path in sorted(ROOT.rglob("README.md")):
        parts = path.relative_to(ROOT).parts[:-1]
        if parts and not any(p.startswith(".") or p in skip for p in parts):
            readmes.append(path)
    return readmes


def parse_rows(readmes):
    """Returns {readme: lines}, the status rows and the summary rows."""
    texts, status_rows, summary_rows = {}, [], []
    for readme in readmes:
        lines = readme.read_text(encoding="utf-8").splitlines(keepends=True)
        texts[readme] = lines
        for i, line in enumerate(lines):
            link = TARGET_LINK.search(line)
            if not line.startswith("|") or not link:
                continue
            target = (readme.parent / link[1]).resolve()
            if DONE in line or TODO in line:
                if target.suffix == ".cpp" or is_exercise_folder(target):
                    status_rows.append((readme, i, target))
            elif target.is_dir() and COUNT_CELL.search(line):
                summary_rows.append((readme, i, target))
    return texts, status_rows, summary_rows


def current_mark(row):
    return DONE if row.rfind(DONE) > row.rfind(TODO) else TODO


def set_mark(row, mark):
    """Put mark in place of the row's status, the last ✅ or ⬜ on the line."""
    i = max(row.rfind(DONE), row.rfind(TODO))
    return row[:i] + mark + row[i + 1:]


def set_count(row, solved, total):
    """Replace the row's last "a/b" cell with solved/total, keeping its padding."""
    cells = list(COUNT_CELL.finditer(row))
    cell = cells[-1]
    old = cell.group(0)
    new = re.sub(r"\d+/\d+", f"{solved}/{total}", old, count=1)
    return row[:cell.start()] + new + row[cell.end():]


def group_of(target):
    """The folder an exercise is reported under, e.g. leetcode/01_hashing or debugging."""
    return rel(target.parent)


def main():
    parser = argparse.ArgumentParser(
        description="Run the exercises' tests and update the Status columns in the README files.")
    parser.add_argument("only", nargs="*", metavar="WORD",
                        help="only run exercises whose path contains one of these words")
    parser.add_argument("-v", "--verbose", action="store_true", help="one line per exercise")
    parser.add_argument("--time-limit", type=float, default=0.5, metavar="SECONDS",
                        help="max run time per LeetCode problem (default: 0.5). Correct answers "
                             "take milliseconds; O(n^2) ones take 1 s or more on the large inputs.")
    args = parser.parse_args()

    texts, status_rows, summary_rows = parse_rows(find_readmes())
    if not status_rows:
        sys.exit("No exercise rows found: README table rows that link to a .cpp file or an "
                 "exercise folder and have a ⬜ or ✅ status.")

    targets = list(dict.fromkeys(target for _, _, target in status_rows))
    before = {}
    for readme, i, target in status_rows:
        before.setdefault(target, current_mark(texts[readme][i]) == DONE)
    selected = [t for t in targets if not args.only or any(w in rel(t) for w in args.only)]
    if not selected:
        sys.exit(f"No exercise path contains {' or '.join(args.only)}.")

    problems = [t for t in selected if t.suffix == ".cpp"]
    tools = (["g++"] if problems else []) + (["make"] if len(problems) < len(selected) else [])
    missing = [tool for tool in tools if not shutil.which(tool)]
    if missing:
        sys.exit(f"{' and '.join(missing)} not found. Install it first.")

    # Compile the LeetCode problems in parallel, then run everything one at a
    # time so the timings stay reliable.
    BUILD_DIR.mkdir(exist_ok=True)
    with ThreadPoolExecutor(max_workers=JOBS) as pool:
        build_errors = dict(zip(problems, pool.map(build, problems)))
    results = {}
    for target in selected:
        if target.suffix == ".cpp":
            error = build_errors[target]
            results[target] = (False, error) if error else run_problem(binary_for(target), args.time_limit)
        else:
            results[target] = run_exercise(target)
    passed = {t: results[t][0] if t in results else before[t] for t in targets}

    # Update the status rows, then the summary counts.
    changed_rows = 0
    edited = set()
    for readme, i, target in status_rows:
        new_row = set_mark(texts[readme][i], DONE if passed[target] else TODO)
        if new_row != texts[readme][i]:
            texts[readme][i] = new_row
            changed_rows += 1
            edited.add(readme)
    for readme, i, folder in summary_rows:
        inside = [t for t in targets if t.suffix == ".cpp" and folder in t.parents]
        new_row = set_count(texts[readme][i], sum(passed[t] for t in inside), len(inside))
        if new_row != texts[readme][i]:
            texts[readme][i] = new_row
            edited.add(readme)
    for readme in edited:
        readme.write_text("".join(texts[readme]), encoding="utf-8")

    # Report: one line per folder, then details for what was asked or what changed.
    groups = {}
    for target in targets:
        groups.setdefault(group_of(target), []).append(target)
    width = max(len(g) for g in groups)
    for group, members in groups.items():
        if args.only and not any(t in results for t in members):
            continue
        solved = sum(passed[t] for t in members)
        mark = DONE if solved == len(members) else "  "
        print(f"{mark} {group:<{width}}  {solved}/{len(members)} solved")
    detailed = [t for t in selected if args.verbose or args.only or passed[t] != before[t]]
    if detailed:
        print()
        for target in detailed:
            ok, detail = results[target]
            change = "" if passed[target] == before[target] else ("  (newly solved)" if ok else "  (no longer passing)")
            print(f"{DONE if ok else TODO} {rel(target)}  {detail}{change}")

    total_solved = sum(passed.values())
    print(f"\n{total_solved}/{len(targets)} solved. ", end="")
    if edited:
        names = ", ".join(rel(r) for r in sorted(edited))
        print(f"Updated {names}" + (f" ({changed_rows} status{'es' if changed_rows != 1 else ''} changed)." if changed_rows else "."))
    else:
        print("README files are already up to date.")


if __name__ == "__main__":
    main()
