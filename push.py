#!/usr/bin/env python3
"""Update the README status, then commit every change as "script push - <what changed>" and push.

It first runs update_status.py, so the README ticks go into the same commit as
the solutions they belong to. The message lists the changed files by name, and a whole new folder by its
folder name. If that's longer than MAX_SUBJECT characters, it shortens to
"script push - exercises", followed by the names of any changed scripts.

Usage:
    ./push.py
"""

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
PREFIX = "script push - "
MAX_SUBJECT = 72  # longest commit subject GitHub shows without cutting it off
SCRIPT_SUFFIXES = {".py", ".sh"}


def git(*args):
    result = subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True)
    if result.returncode != 0:
        sys.exit(f"git {args[0]} failed:\n{result.stderr}")
    return result.stdout


def changed_paths():
    """Changed paths relative to the repo; a new folder shows up once, as 'folder/'."""
    paths = []
    for line in git("status", "--porcelain").splitlines():
        path = line[3:].split(" -> ")[-1]  # a rename shows as "old -> new"
        paths.append(path.strip('"'))
    return paths


def name(path):
    """leetcode/02_x.cpp -> 02_x.cpp, debugging/ -> debugging/"""
    return Path(path).name + ("/" if path.endswith("/") else "")


def message(paths):
    full = PREFIX + ", ".join(name(p) for p in paths)
    if len(full) <= MAX_SUBJECT:
        return full
    scripts = [name(p) for p in paths if Path(p).suffix in SCRIPT_SUFFIXES]
    exercises = ["exercises"] if len(scripts) < len(paths) else []
    return PREFIX + ", ".join(exercises + scripts)


def update_status():
    """Run update_status.py. If it can't run, warn but still commit and push."""
    script = ROOT / "update_status.py"
    if subprocess.run([sys.executable, str(script)], cwd=ROOT).returncode != 0:
        print("Warning: update_status.py failed, so the README ticks may be out of date.\n")
    else:
        print()


def main():
    update_status()
    paths = changed_paths()
    if not paths:
        print("Nothing to commit.")
        return

    msg = message(paths)
    git("add", "-A")
    git("commit", "-m", msg)
    print(f"Committed: {msg}")

    if subprocess.run(["git", "push"], cwd=ROOT).returncode != 0:
        sys.exit("git push failed (the commit is saved locally; run git push again)")


if __name__ == "__main__":
    main()
