# Debugging exercises

Small C++ codebases with bugs planted in them, modelled on the code-repository question in Amazon's SDE online assessment. Each one gives you an unfamiliar codebase, some bug reports and a few tests, and you have to find and fix the bugs before the timer runs out.

| # | Codebase | Time |
|---|---|---|
| [01](01_review_queue/TASK.md) | Pull request review service: reviewer assignment, approvals, merges | 45 min |
| [02](02_warehouse_inventory/TASK.md) | Warehouse inventory: stock reservations and customer orders | 45 min |
| [03](03_checkout_pricing/TASK.md) | Checkout pricing: shopping cart, coupons, shipping | 45 min |

## What's in an exercise

- `TASK.md`: what the code does, the bug reports and the commands. Start here.
- `src/`: the application, a few files and 130–180 lines.
- `tests/visible_tests.cpp`: the tests you're given. Some fail, and some bugs aren't covered by any of them.
- `tests/hidden_tests.cpp`: stands in for the assessment's hidden tests, which check every bug report. Don't open it until you've finished.

The answers, and the patterns behind the bugs, are in [ANSWERS.md](ANSWERS.md). Read an exercise's section only after finishing it.

## Commands

Run these inside an exercise folder. You need `g++` and `make`.

```bash
make test            # build and run the visible tests
make test T=Merge    # run only the tests whose name contains "Merge"
make check           # visible + hidden tests: your final score
make clean           # delete the build folder
```

## How to practise

1. **Set a 45-minute timer.** The assessment gives 100 minutes for two questions.
2. **Read `TASK.md`, then the headers in `src/`.** Their comments say what the code should do. The bugs are wherever the code does something else.
3. **Run `make test`.** Read the failures and any compiler warnings.
4. **Turn each bug report into a test** before looking for the cause, unless a failing test already covers it. A test with the smallest input that shows the bug tells you what to look for, and tells you when it's fixed.
5. **Find the first point where the state goes wrong.** Print values at each step (`std::cerr << ...`), or step through with `gdb build/visible_tests` (the build includes debug symbols). Then read the suspicious lines slowly, asking what each one *actually* does, not what it was meant to do.
6. **Fix it, then rerun all the tests**, because a fix can reveal another bug. Finish with `make check`.

**Using an AI assistant:** the assessment gives you one, so practise using it well. Ask it to explain a function, or to write a test that reproduces a bug report. Don't ask it to find all the bugs: that skips the practice, and in the assessment you need to understand a fix to trust it.
