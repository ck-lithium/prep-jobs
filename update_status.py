#!/usr/bin/env python3
"""Run every exercise's tests and update the Status columns in README.md.

Exercises are README table rows that link to a .cpp file (a LeetCode problem)
or to a folder (a debugging exercise). A row gets ✅ when all of its tests
pass, ⬜ otherwise, and goes back to ⬜ if it stops passing.

  - A LeetCode problem is compiled and run with a time limit, so a solution
    that is correct but too slow doesn't count.
  - A debugging exercise runs `make check`: its visible and hidden tests.

Usage:
    ./update_status.py                   # 0.5 s per LeetCode problem
    ./update_status.py --time-limit 2    # allow more time per problem
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
README = ROOT / "README.md"
BUILD_DIR = ROOT / ".build"  # compiled LeetCode tests, reused until their .cpp file changes
COMPILE = ["g++", "-std=c++17", "-O2", "-Wall"]
JOBS = min(8, os.cpu_count() or 1)
EXERCISE_TIMEOUT = 120  # seconds for a debugging exercise's `make check`, build included
DONE, TODO = "✅", "⬜"

# A row's first local link: [01](leetcode/01_x.cpp) or [01](debugging/01_x/)
TARGET_LINK = re.compile(r"\]\(([^()\s:]+?(?:\.cpp|/))\)")
SUMMARY = re.compile(r"(\d+)/(\d+) tests passed")  # last line of every test run
COMPILE_ERROR = re.compile(r"^(.+?):(\d+):\d+: (?:fatal )?error: (.*)$")


def label(target):
    return target.stem if target.suffix == ".cpp" else target.name


def binary_for(src):
    """leetcode/01_x.cpp -> .build/leetcode__01_x"""
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
    if not (folder / "Makefile").is_file():
        return False, "no Makefile found"
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


def set_mark(row, mark):
    """Put mark in place of the row's status, the last ✅ or ⬜ on the line."""
    i = max(row.rfind(DONE), row.rfind(TODO))
    return row[:i] + mark + row[i + 1:]


def main():
    parser = argparse.ArgumentParser(
        description="Run every exercise's tests and update the Status columns in README.md.")
    parser.add_argument("--time-limit", type=float, default=0.5, metavar="SECONDS",
                        help="max run time per LeetCode problem (default: 0.5). Correct answers "
                             "take milliseconds; O(n^2) ones take 1 s or more on the large inputs.")
    args = parser.parse_args()

    lines = README.read_text(encoding="utf-8").splitlines(keepends=True)
    rows = {}  # line index in README -> the .cpp file or folder that row links to
    for i, line in enumerate(lines):
        link = TARGET_LINK.search(line)
        if line.startswith("|") and link and (DONE in line or TODO in line):
            rows[i] = ROOT / link[1]
    if not rows:
        sys.exit("README.md has no exercise rows: table rows that link to a .cpp file or "
                 "a folder and have a ⬜ or ✅ status.")

    targets = list(dict.fromkeys(rows.values()))
    problems = [t for t in targets if t.suffix == ".cpp"]
    tools = (["g++"] if problems else []) + (["make"] if len(problems) < len(targets) else [])
    missing = [tool for tool in tools if not shutil.which(tool)]
    if missing:
        sys.exit(f"{' and '.join(missing)} not found. Install it first.")

    # Compile the LeetCode problems in parallel, then run everything one at a
    # time so the timings stay reliable.
    BUILD_DIR.mkdir(exist_ok=True)
    with ThreadPoolExecutor(max_workers=JOBS) as pool:
        build_errors = dict(zip(problems, pool.map(build, problems)))

    width = max(len(label(t)) for t in targets)
    passed = {}
    for target in targets:
        if target.suffix == ".cpp":
            error = build_errors[target]
            ok, detail = (False, error) if error else run_problem(binary_for(target), args.time_limit)
        else:
            ok, detail = run_exercise(target)
        passed[target] = ok
        print(f"{DONE if ok else TODO} {label(target):<{width}}  {detail}")

    changed = 0
    for i, target in rows.items():
        new_row = set_mark(lines[i], DONE if passed[target] else TODO)
        if new_row != lines[i]:
            lines[i] = new_row
            changed += 1

    print(f"\n{sum(passed.values())}/{len(targets)} done. ", end="")
    if changed:
        README.write_text("".join(lines), encoding="utf-8")
        print(f"Updated README.md ({changed} row{'s' if changed > 1 else ''} changed).")
    else:
        print("README.md is already up to date.")


if __name__ == "__main__":
    main()
