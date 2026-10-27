# prep-jobs

My coding-interview practice, in C++. Each folder is one interview, named `<company>_<date>`, and holds a set of LeetCode-style problems picked for that company.

Each problem is a single self-contained `.cpp` file with:

- the full problem statement, examples and constraints in a comment at the top
- the target time and space complexity
- a short "how to spot this pattern" note
- a `Solution` class to fill in
- a small test harness that prints `PASS` / `FAIL` per case. Some files also include one large input that an O(n²) solution won't finish in time.

## Running a problem

```bash
cd amazon_2026-10-28
g++ -std=c++17 -O2 -Wall 01_hashing_longestConsecutiveSequence.cpp && ./a.out
```

The files use `<bits/stdc++.h>`, so they need GCC (on macOS, install `g++` with Homebrew rather than using the default Clang).

## Tracking progress

`update_status.py` compiles and tests every problem in the tables below and updates the Status column: ✅ when all of a file's tests pass within the time limit, ⬜ otherwise.

```bash
./update_status.py                   # time limit: 0.5 s per file
./update_status.py --time-limit 2    # allow more time
```

The time limit catches slow solutions: correct answers finish in milliseconds, while O(n²) ones take 1 s or more on the large inputs. The script needs Python 3 and `g++`, and it caches compiled tests in `.build/`, rebuilding only the files that changed.

## Amazon — `amazon_2026-10-28/`

Prep for the Amazon online assessment (OA). The set covers 16 patterns, one Medium problem each. That's broad rather than deep: the goal is to recognise which pattern a new problem calls for.

| # | Pattern | Problem | Target | Status |
|---|---------|---------|--------|--------|
| [01](amazon_2026-10-28/01_hashing_longestConsecutiveSequence.cpp) | Hashing | [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | O(n) | ✅ |
| [02](amazon_2026-10-28/02_twoPointers_containerWithMostWater.cpp) | Two pointers | [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | O(n), O(1) space | ✅ |
| [03](amazon_2026-10-28/03_slidingWindow_longestSubstringNoRepeats.cpp) | Sliding window | [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | O(n) | ⬜ |
| [04](amazon_2026-10-28/04_prefixSum_subarraySumEqualsK.cpp) | Prefix sum | [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | O(n) | ⬜ |
| [05](amazon_2026-10-28/05_binarySearchOnAnswer_shipWithinDays.cpp) | Binary search on the answer | [1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | O(n log Σw) | ⬜ |
| [06](amazon_2026-10-28/06_heap_kClosestPoints.cpp) | Heap / top K | [973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | O(n log k) | ⬜ |
| [07](amazon_2026-10-28/07_intervals_mergeIntervals.cpp) | Intervals | [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) | O(n log n) | ⬜ |
| [08](amazon_2026-10-28/08_greedy_partitionLabels.cpp) | Greedy | [763. Partition Labels](https://leetcode.com/problems/partition-labels/) | O(n) | ⬜ |
| [09](amazon_2026-10-28/09_monotonicStack_dailyTemperatures.cpp) | Monotonic stack | [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) | O(n) | ⬜ |
| [10](amazon_2026-10-28/10_gridBFS_rottingOranges.cpp) | Grid BFS | [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | O(m·n) | ⬜ |
| [11](amazon_2026-10-28/11_graphDFS_numberOfIslands.cpp) | Graph DFS | [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) | O(m·n) | ⬜ |
| [12](amazon_2026-10-28/12_topologicalSort_courseSchedule.cpp) | Topological sort | [207. Course Schedule](https://leetcode.com/problems/course-schedule/) | O(V + E) | ⬜ |
| [13](amazon_2026-10-28/13_dp1D_coinChange.cpp) | DP (1D) | [322. Coin Change](https://leetcode.com/problems/coin-change/) | O(amount · coins) | ⬜ |
| [14](amazon_2026-10-28/14_dp2D_longestCommonSubsequence.cpp) | DP (2D) | [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | O(n·m) | ⬜ |
| [15](amazon_2026-10-28/15_trie_searchSuggestions.cpp) | Trie | [1268. Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) | — | ⬜ |
| [16](amazon_2026-10-28/16_design_lruCache.cpp) | Design | [146. LRU Cache](https://leetcode.com/problems/lru-cache/) | O(1) per op | ⬜ |

Click a problem's number to open its file. Warm-up, outside the set: [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/) in `reverseInteger.cpp` ✅

### Spotting the pattern

| Pattern                     | Reach for it when…                                                                              |
|-----------------------------|-------------------------------------------------------------------------------------------------|
| Hashing                     | You keep asking "is X in the input?" and need the answer in O(1).                               |
| Two pointers                | You pick a pair (i, j) and comparing the two ends rules one of them out. Common on sorted arrays. |
| Sliding window              | Longest / shortest contiguous subarray or substring that satisfies a condition.                 |
| Prefix sum                  | Count or find subarrays with sum exactly X, especially when values can be negative.             |
| Binary search on the answer | "Minimum X such that it's possible", where any bigger X also works (capacity, speed, time).     |
| Heap / top K                | "Top k", "k-th largest", or repeatedly taking the current smallest / largest item.              |
| Intervals                   | Ranges or time slots (meetings, bookings). Sort by start first.                                 |
| Greedy                      | One local choice at a time never hurts the final answer. Often needs a precompute step.         |
| Monotonic stack             | Next greater / smaller element, "how many days until…", histogram areas.                        |
| Grid BFS                    | Minimum steps in a grid or unweighted graph, or something spreading from several sources.       |
| Graph DFS                   | Count groups / regions / connected components, flood fill.                                     |
| Topological sort            | Dependencies, prerequisites, build order, cycle detection in a directed graph.                  |
| DP (1D)                     | Min / max / number of ways to reach a target, where greedy can be wrong.                        |
| DP (2D)                     | Two strings or arrays compared position by position, or paths in a grid.                        |
| Trie                        | Many "starts with" queries over a fixed set of words (autocomplete).                            |
| Design                      | "Implement a class where every operation is O(1)": usually two data structures together.        |
