#!/usr/bin/env python3
"""Erase solutions, so the exercises can be done again from scratch.

The unsolved version of every exercise is kept in .originals/, at the same path
as the exercise. Erasing puts it back:

  - A LeetCode problem gets its original code back: everything between the
    problem statement and the tests. The statement and the tests stay as they
    are now, so later fixes to them are kept.
  - A debugging exercise gets its original, buggy src/ folder back.

Then update_status.py runs on the erased exercises, so the README files show ⬜.

Erased solutions stay in git history. Changes that aren't committed yet would be
lost for good, so the script refuses to erase them unless you pass --force.

Usage:
    ./erase_solutions.py coinChange              # the exercises whose path contains these words
    ./erase_solutions.py 00_initial debugging
    ./erase_solutions.py --all                   # everything, e.g. to hand the repo to someone else
    ./erase_solutions.py -n 00_initial           # only list what would be erased
    ./erase_solutions.py -y coinChange           # don't ask for confirmation

When you add an exercise, put its unsolved version in .originals/ too, at the same path.
"""

import argparse
import shutil
import subprocess
import sys

import update_status as status

ROOT = status.ROOT
ORIGINALS = ROOT / ".originals"


def code_bounds(lines):
    """Where a problem's code is: from after the statement's closing */ up to the
    "// ----" line above "// Tests.". None if the file no longer has those markers."""
    start = next((i + 1 for i, line in enumerate(lines) if line.strip() == "*/"), None)
    tests = next((i for i, line in enumerate(lines) if line.startswith("// Tests.")), None)
    if start is None or tests is None or tests - 1 < start or not lines[tests - 1].startswith("// ---"):
        return None
    return start, tests - 1


def erased_problem(current, original):
    """The problem's text with its code replaced by the original code."""
    cur, orig = current.splitlines(keepends=True), original.splitlines(keepends=True)
    cur_bounds, orig_bounds = code_bounds(cur), code_bounds(orig)
    if cur_bounds is None or orig_bounds is None:
        return original  # the markers were edited away: restore the whole file
    return "".join(cur[:cur_bounds[0]] + orig[orig_bounds[0]:orig_bounds[1]] + cur[cur_bounds[1]:])


def src_files(folder):
    return {p.relative_to(folder): p.read_bytes() for p in folder.rglob("*") if p.is_file()}


def plan(target):
    """What erasing target means: (needs erasing, original path), or None if no original is saved."""
    original = ORIGINALS / status.rel(target)
    if target.suffix == ".cpp":
        if not original.is_file():
            return None
        current = target.read_text(encoding="utf-8") if target.is_file() else ""
        return erased_problem(current, original.read_text(encoding="utf-8")) != current, original
    original_src = original / "src"
    if not original_src.is_dir():
        return None
    current_src = target / "src"
    differs = not current_src.is_dir() or src_files(current_src) != src_files(original_src)
    return differs, original_src


def erase(target, original):
    if target.suffix == ".cpp":
        current = target.read_text(encoding="utf-8") if target.is_file() else ""
        target.write_text(erased_problem(current, original.read_text(encoding="utf-8")), encoding="utf-8")
    else:
        shutil.rmtree(target / "src", ignore_errors=True)
        shutil.copytree(original, target / "src")


def git(*args):
    """Runs a git command in the repo. Returns its output, or None if git or the repo is missing."""
    try:
        result = subprocess.run(["git", "-C", str(ROOT), *args], capture_output=True, text=True)
    except FileNotFoundError:
        return None
    return result.stdout if result.returncode == 0 else None


def main():
    parser = argparse.ArgumentParser(
        description="Put exercises back to their unsolved version, so they can be done again.")
    parser.add_argument("only", nargs="*", metavar="WORD",
                        help="erase the exercises whose path contains one of these words")
    parser.add_argument("--all", action="store_true", help="erase every exercise")
    parser.add_argument("-n", "--dry-run", action="store_true", help="only list what would be erased")
    parser.add_argument("-y", "--yes", action="store_true", help="don't ask for confirmation")
    parser.add_argument("--force", action="store_true",
                        help="also erase changes that aren't committed (they're lost for good)")
    args = parser.parse_args()
    if not args.only and not args.all:
        parser.error("say which exercises to erase (words from their paths), or pass --all")
    if args.only and args.all:
        parser.error("pass either words or --all, not both")

    _, status_rows, _ = status.parse_rows(status.find_readmes())
    targets = list(dict.fromkeys(target for _, _, target in status_rows))
    selected = [t for t in targets if args.all or any(w in status.rel(t) for w in args.only)]
    if not selected:
        sys.exit(f"No exercise path contains {' or '.join(args.only)}.")

    to_erase, unchanged, no_original = [], [], []
    for target in selected:
        found = plan(target)
        if found is None:
            no_original.append(target)
        elif found[0]:
            to_erase.append((target, found[1]))
        else:
            unchanged.append(target)

    for target in no_original:
        print(f"skipped {status.rel(target)}: no unsolved version saved in .originals/")
    if unchanged:
        print(f"{len(unchanged)} already unsolved, nothing to erase there.")
    if not to_erase:
        print("Nothing to erase.")
        return

    # Changes that aren't committed have no copy in git history.
    head = git("rev-parse", "--short", "HEAD")
    if head is None:
        print("Warning: this isn't a git repository, so erased solutions can't be recovered.")
    else:
        paths = [str(t.relative_to(ROOT) / ("" if t.suffix == ".cpp" else "src")) for t, _ in to_erase]
        uncommitted = git("status", "--porcelain", "--", *paths)
        if uncommitted and not args.force:
            print("\nThese have changes that aren't committed yet:")
            print("".join(f"  {line[3:]}\n" for line in uncommitted.splitlines()), end="")
            sys.exit("Commit them first (./push.py), or pass --force to erase them anyway.")

    print(f"\n{'Would erase' if args.dry_run else 'Erasing'} {len(to_erase)} exercise(s):")
    for target, _ in to_erase:
        print(f"  {status.rel(target)}")
    if args.dry_run:
        return
    if not args.yes:
        try:
            answer = input("Erase them? [y/N] ")
        except EOFError:
            answer = ""
        if answer.strip().lower() not in ("y", "yes"):
            sys.exit("Nothing erased.")

    for target, original in to_erase:
        erase(target, original)
    print(f"Erased {len(to_erase)} exercise(s).")
    if head is not None:
        target = to_erase[0][0]
        example = status.rel(target) + ("" if target.suffix == ".cpp" else "/src")
        print(f"Your solutions are still in git history. To get one back:\n"
              f"  git checkout {head.strip()} -- {example}")

    print("\nUpdating the README files:", flush=True)  # before update_status.py prints
    words = [] if args.all else [status.rel(target) for target, _ in to_erase]
    subprocess.run([sys.executable, str(ROOT / "update_status.py"), *words])


if __name__ == "__main__":
    main()
