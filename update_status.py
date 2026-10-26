#!/usr/bin/env python3
"""Run every problem's tests and update the Status column in README.md.

Problems are the README table rows that link to a .cpp file. Each file is
compiled and run, and its row gets ✅ if every test passes within the time
limit, ⬜ otherwise. A row goes back to ⬜ if its problem stops passing.

Usage:
    ./update_status.py                   # 0.5 s per file
    ./update_status.py --time-limit 2    # allow more time per file
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
BUILD_DIR = ROOT / ".build"  # compiled tests, reused until their .cpp file changes
COMPILE = ["g++", "-std=c++17", "-O2", "-Wall"]
DONE, TODO = "✅", "⬜"

CPP_LINK = re.compile(r"\]\(([^()\s]+\.cpp)\)")  # e.g. [01](amazon_2026-10-28/01_x.cpp)
SUMMARY = re.compile(r"(\d+)/(\d+) tests passed")  # last line of every test run
COMPILE_ERROR = re.compile(r":(\d+):\d+: (?:fatal )?error: (.*)")


def binary_for(src):
    """amazon_2026-10-28/01_x.cpp -> .build/amazon_2026-10-28__01_x"""
    return BUILD_DIR / "__".join(src.relative_to(ROOT).with_suffix("").parts)


def build(src):
    """Compile src if needed. Returns None on success, otherwise what went wrong."""
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
    for line in result.stderr.splitlines():
        error = COMPILE_ERROR.search(line)
        if error and line.startswith(f"{src}:"):
            return f"compile error, line {error[1]}: {error[2]}"
    return "compile error (build the file by hand to see it)"


def run_tests(exe, time_limit):
    """Run a compiled test file. Returns (all tests passed, one-line summary)."""
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


def set_mark(row, mark):
    """Put mark in place of the row's status, the last ✅ or ⬜ on the line."""
    i = max(row.rfind(DONE), row.rfind(TODO))
    return row[:i] + mark + row[i + 1:]


def main():
    parser = argparse.ArgumentParser(
        description="Run every problem's tests and update the Status column in README.md.")
    parser.add_argument("--time-limit", type=float, default=0.5, metavar="SECONDS",
                        help="max run time per file (default: 0.5). Correct answers take "
                             "milliseconds; O(n^2) ones take 1 s or more on the large inputs.")
    args = parser.parse_args()
    if not shutil.which(COMPILE[0]):
        sys.exit(f"{COMPILE[0]} not found. Install GCC first.")

    lines = README.read_text(encoding="utf-8").splitlines(keepends=True)
    rows = {}  # line index in README -> the .cpp file that row links to
    for i, line in enumerate(lines):
        link = CPP_LINK.search(line)
        if line.startswith("|") and link and (DONE in line or TODO in line):
            rows[i] = ROOT / link[1]
    if not rows:
        sys.exit("README.md has no problem rows: table rows that link to a .cpp file "
                 "and have a ⬜ or ✅ status.")

    # Compile in parallel, then run one at a time so the timings stay reliable.
    BUILD_DIR.mkdir(exist_ok=True)
    sources = list(dict.fromkeys(rows.values()))
    with ThreadPoolExecutor(max_workers=min(8, os.cpu_count() or 1)) as pool:
        build_errors = dict(zip(sources, pool.map(build, sources)))

    width = max(len(src.stem) for src in sources)
    passed = {}
    for src in sources:
        error = build_errors[src]
        ok, detail = (False, error) if error else run_tests(binary_for(src), args.time_limit)
        passed[src] = ok
        print(f"{DONE if ok else TODO} {src.stem:<{width}}  {detail}")

    changed = 0
    for i, src in rows.items():
        new_row = set_mark(lines[i], DONE if passed[src] else TODO)
        if new_row != lines[i]:
            lines[i] = new_row
            changed += 1

    print(f"\n{sum(passed.values())}/{len(sources)} solved. ", end="")
    if changed:
        README.write_text("".join(lines), encoding="utf-8")
        print(f"Updated README.md ({changed} row{'s' if changed > 1 else ''} changed).")
    else:
        print("README.md is already up to date.")


if __name__ == "__main__":
    main()
