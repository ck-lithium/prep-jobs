# Exercise 01: Pull request review service

**Time limit: 45 minutes.** Start a timer before reading on.

## The codebase

A small service that assigns code reviewers to pull requests (PRs), then tracks approvals and merges. The rules it should follow are in the comment at the top of `src/review_service.h`.

| File | What's in it |
|---|---|
| `src/review_service.h`, `.cpp` | Opening, approving and merging PRs |
| `src/team.h`, `.cpp` | The team, and how many reviews each person has open |
| `src/pull_request.h` | The `PullRequest` struct |
| `tests/visible_tests.cpp` | The tests you're given. Some of them fail. |
| `tests/hidden_tests.cpp` | Stands in for the assessment's hidden tests. Don't open it until you've finished. |

## Your task

Users reported the bugs below. Fix all of them.

Some bugs make visible tests fail. Others aren't covered by any visible test, so reproduce them with a test of your own first. You can change anything in `src/` and add tests to `tests/visible_tests.cpp`. Keep the public functions' names and parameters as they are, because the hidden tests call them.

### Bug reports

1. "Bob has been assigned to every single PR this week, while Carol and Dave got none."
2. "Our 200-line PR was approved after a single review. The policy says 200 lines or more need two."
3. "The merge audit log lists PR #2 twice. Two different PRs got the same ID."
4. "Dave approved my big PR twice by accident, and it became mergeable with only his approval."

## Commands

Run these in this folder:

```bash
make test            # build and run the visible tests
make test T=Merge    # run only the tests whose name contains "Merge"
make check           # visible + hidden tests: your final score
```

When you're done, or the timer runs out, run `make check`, then compare with [../ANSWERS.md](../ANSWERS.md).
