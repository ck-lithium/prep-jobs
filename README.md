# prep-jobs

My coding-interview practice, in C++. There are two kinds of exercises:

- **[`leetcode/`](leetcode/)**: 116 algorithm problems grouped by pattern. Each is a single file with the problem statement and tests.
- **[`debugging/`](debugging/)**: small buggy codebases with bug reports and tests. You find and fix the bugs against the clock.

## Tracking progress

`update_status.py` runs the exercises' tests and updates the Status columns in the README files: ✅ when all of an exercise's tests pass, ⬜ otherwise. It also keeps the "Solved" counts below up to date.

```bash
./update_status.py                   # everything, with a summary per folder
./update_status.py hashing tree      # only the exercises whose path contains these words
./update_status.py -v                # one line per exercise
./update_status.py --time-limit 2    # give LeetCode problems 2 s instead of 0.5 s
```

- **LeetCode problems** run with a time limit, which catches slow solutions: correct answers finish in milliseconds, while O(n²) ones take a second or more on the large inputs. Compiled tests are cached in `.build/`, and only the files that changed are rebuilt.
- **Debugging exercises** run `make check`, which includes the hidden tests, so ✅ means every bug report is fixed.

The script needs Python 3, `g++` and `make`. `push.py` runs it before every commit and push.

## LeetCode

116 problems in [`leetcode/`](leetcode/): an initial set of 16, one per pattern, then 20 folders of 5 problems each, from easy to hard. [leetcode/README.md](leetcode/README.md) lists every problem with its status, and has a table on how to spot each pattern.

| Folder | Pattern | Solved |
|--------|---------|--------|
| [00_initial](leetcode/00_initial/) | One problem per pattern, as a first pass | 13/16 |
| [01_hashing](leetcode/01_hashing/) | Hashing | 0/5 |
| [02_two_pointers](leetcode/02_two_pointers/) | Two pointers | 0/5 |
| [03_sliding_window](leetcode/03_sliding_window/) | Sliding window | 0/5 |
| [04_prefix_sum](leetcode/04_prefix_sum/) | Prefix sum | 0/5 |
| [05_binary_search](leetcode/05_binary_search/) | Binary search | 0/5 |
| [06_heap](leetcode/06_heap/) | Heap / top K | 0/5 |
| [07_intervals](leetcode/07_intervals/) | Intervals | 0/5 |
| [08_greedy](leetcode/08_greedy/) | Greedy | 0/5 |
| [09_monotonic_stack](leetcode/09_monotonic_stack/) | Monotonic stack | 0/5 |
| [10_grid_bfs](leetcode/10_grid_bfs/) | Grid BFS | 0/5 |
| [11_graph_dfs](leetcode/11_graph_dfs/) | Graph DFS | 0/5 |
| [12_topological_sort](leetcode/12_topological_sort/) | Topological sort | 0/5 |
| [13_dp_1d](leetcode/13_dp_1d/) | DP (1D) | 0/5 |
| [14_dp_2d](leetcode/14_dp_2d/) | DP (2D) | 0/5 |
| [15_trie](leetcode/15_trie/) | Trie | 0/5 |
| [16_design](leetcode/16_design/) | Design | 0/5 |
| [17_linked_list](leetcode/17_linked_list/) | Linked list | 0/5 |
| [18_binary_tree](leetcode/18_binary_tree/) | Binary tree | 0/5 |
| [19_backtracking](leetcode/19_backtracking/) | Backtracking | 0/5 |
| [20_shortest_path_union_find](leetcode/20_shortest_path_union_find/) | Shortest paths & union-find | 0/5 |

## Debugging

Small buggy codebases in [`debugging/`](debugging/). Each one has four planted bugs, a `TASK.md` with user bug reports, visible tests (some failing) and hidden tests. You get 45 minutes to find and fix all four. [debugging/README.md](debugging/README.md) explains how to work through one.

| # | Codebase | Bugs | Status |
|---|----------|------|--------|
| [01](debugging/01_review_queue/) | Pull request review service: reviewer assignment, approvals, merges | 4 | ⬜ |
| [02](debugging/02_warehouse_inventory/) | Warehouse inventory: stock reservations and customer orders | 4 | ⬜ |
| [03](debugging/03_checkout_pricing/) | Checkout pricing: shopping cart, coupons, shipping | 4 | ⬜ |
