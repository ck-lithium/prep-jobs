# LeetCode practice

116 problems in C++, grouped by the pattern that solves them:

- **[`00_initial/`](00_initial/)**: 16 problems, one per pattern, as a first pass. Start here.
- **20 pattern folders**: 5 problems each, ordered from easy to hard. Folders 01–16 go deeper into the patterns of the initial set; 17–20 add linked lists, binary trees, backtracking, and shortest paths / union-find.

Each problem is a single self-contained `.cpp` file with:

- the problem statement (rewritten), examples, constraints and the target complexity in a comment at the top, plus a link to the original on LeetCode
- a `Solution` class (or the class to design) to fill in
- tests that print `PASS` / `FAIL` per case. Many files end with one large input that a too-slow solution won't finish in time.

## Running a problem

```bash
cd leetcode/01_hashing
g++ -std=c++17 -O2 -Wall 01_twoSum.cpp && ./a.out
```

The files use `<bits/stdc++.h>`, so they need GCC (on macOS, install `g++` with Homebrew rather than using the default Clang).

To update the Status columns below, run the script from the repo root. A word limits it to the matching folders:

```bash
./update_status.py              # everything
./update_status.py hashing      # only leetcode/01_hashing
```

## Initial set: `00_initial/`

| # | Pattern | Problem | Target | Status |
|---|---------|---------|--------|--------|
| [01](00_initial/01_hashing_longestConsecutiveSequence.cpp) | Hashing | [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) | O(n) | ✅ |
| [02](00_initial/02_twoPointers_containerWithMostWater.cpp) | Two pointers | [11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) | O(n), O(1) space | ✅ |
| [03](00_initial/03_slidingWindow_longestSubstringNoRepeats.cpp) | Sliding window | [3. Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | O(n) | ✅ |
| [04](00_initial/04_prefixSum_subarraySumEqualsK.cpp) | Prefix sum | [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) | O(n) | ✅ |
| [05](00_initial/05_binarySearchOnAnswer_shipWithinDays.cpp) | Binary search on the answer | [1011. Capacity To Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) | O(n log Σw) | ✅ |
| [06](00_initial/06_heap_kClosestPoints.cpp) | Heap / top K | [973. K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/) | O(n log k) | ✅ |
| [07](00_initial/07_intervals_mergeIntervals.cpp) | Intervals | [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/) | O(n log n) | ⬜ |
| [08](00_initial/08_greedy_partitionLabels.cpp) | Greedy | [763. Partition Labels](https://leetcode.com/problems/partition-labels/) | O(n) | ⬜ |
| [09](00_initial/09_monotonicStack_dailyTemperatures.cpp) | Monotonic stack | [739. Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) | O(n) | ⬜ |
| [10](00_initial/10_gridBFS_rottingOranges.cpp) | Grid BFS | [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) | O(m·n) | ⬜ |
| [11](00_initial/11_graphDFS_numberOfIslands.cpp) | Graph DFS | [200. Number of Islands](https://leetcode.com/problems/number-of-islands/) | O(m·n) | ⬜ |
| [12](00_initial/12_topologicalSort_courseSchedule.cpp) | Topological sort | [207. Course Schedule](https://leetcode.com/problems/course-schedule/) | O(V + E) | ⬜ |
| [13](00_initial/13_dp1D_coinChange.cpp) | DP (1D) | [322. Coin Change](https://leetcode.com/problems/coin-change/) | O(amount · coins) | ⬜ |
| [14](00_initial/14_dp2D_longestCommonSubsequence.cpp) | DP (2D) | [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | O(n·m) | ⬜ |
| [15](00_initial/15_trie_searchSuggestions.cpp) | Trie | [1268. Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/) | — | ⬜ |
| [16](00_initial/16_design_lruCache.cpp) | Design | [146. LRU Cache](https://leetcode.com/problems/lru-cache/) | O(1) per op | ⬜ |

Warm-up, outside the set: [7. Reverse Integer](https://leetcode.com/problems/reverse-integer/) in `00_initial/reverseInteger.cpp` ✅

## By pattern

Each folder goes from easy to hard. Click a number to open the file, or a title to open the problem on LeetCode.

### Hashing: `01_hashing/`

*Reach for it when:* You keep asking "is X in the input?" and need the answer in O(1).

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](01_hashing/01_twoSum.cpp) | [1. Two Sum](https://leetcode.com/problems/two-sum/) | Easy | ⬜ |
| [02](01_hashing/02_validAnagram.cpp) | [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/) | Easy | ⬜ |
| [03](01_hashing/03_groupAnagrams.cpp) | [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/) | Medium | ⬜ |
| [04](01_hashing/04_validSudoku.cpp) | [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/) | Medium | ⬜ |
| [05](01_hashing/05_firstMissingPositive.cpp) | [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/) | Hard | ⬜ |

### Two pointers: `02_two_pointers/`

*Reach for it when:* You pick a pair (i, j) and comparing the two ends rules one of them out. Common on sorted arrays.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](02_two_pointers/01_validPalindrome.cpp) | [125. Valid Palindrome](https://leetcode.com/problems/valid-palindrome/) | Easy | ⬜ |
| [02](02_two_pointers/02_twoSumII.cpp) | [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | Medium | ⬜ |
| [03](02_two_pointers/03_threeSum.cpp) | [15. 3Sum](https://leetcode.com/problems/3sum/) | Medium | ⬜ |
| [04](02_two_pointers/04_sortColors.cpp) | [75. Sort Colors](https://leetcode.com/problems/sort-colors/) | Medium | ⬜ |
| [05](02_two_pointers/05_trappingRainWater.cpp) | [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) | Hard | ⬜ |

### Sliding window: `03_sliding_window/`

*Reach for it when:* Longest / shortest contiguous subarray or substring that satisfies a condition.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](03_sliding_window/01_bestTimeToBuyAndSellStock.cpp) | [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | Easy | ⬜ |
| [02](03_sliding_window/02_longestRepeatingCharacterReplacement.cpp) | [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/) | Medium | ⬜ |
| [03](03_sliding_window/03_permutationInString.cpp) | [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/) | Medium | ⬜ |
| [04](03_sliding_window/04_maxConsecutiveOnesIII.cpp) | [1004. Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/) | Medium | ⬜ |
| [05](03_sliding_window/05_minimumWindowSubstring.cpp) | [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) | Hard | ⬜ |

### Prefix sum: `04_prefix_sum/`

*Reach for it when:* Count or find subarrays with sum exactly X, especially when values can be negative.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](04_prefix_sum/01_rangeSumQueryImmutable.cpp) | [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) | Easy | ⬜ |
| [02](04_prefix_sum/02_productOfArrayExceptSelf.cpp) | [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | Medium | ⬜ |
| [03](04_prefix_sum/03_continuousSubarraySum.cpp) | [523. Continuous Subarray Sum](https://leetcode.com/problems/continuous-subarray-sum/) | Medium | ⬜ |
| [04](04_prefix_sum/04_subarraySumsDivisibleByK.cpp) | [974. Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | Medium | ⬜ |
| [05](04_prefix_sum/05_numberOfSubmatricesThatSumToTarget.cpp) | [1074. Number of Submatrices That Sum to Target](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/) | Hard | ⬜ |

### Binary search: `05_binary_search/`

*Reach for it when:* A sorted array, or "minimum X such that it's possible" where any bigger X also works (capacity, speed, time).

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](05_binary_search/01_binarySearch.cpp) | [704. Binary Search](https://leetcode.com/problems/binary-search/) | Easy | ⬜ |
| [02](05_binary_search/02_searchInRotatedSortedArray.cpp) | [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | Medium | ⬜ |
| [03](05_binary_search/03_kokoEatingBananas.cpp) | [875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) | Medium | ⬜ |
| [04](05_binary_search/04_minDaysToMakeBouquets.cpp) | [1482. Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) | Medium | ⬜ |
| [05](05_binary_search/05_splitArrayLargestSum.cpp) | [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) | Hard | ⬜ |

### Heap / top K: `06_heap/`

*Reach for it when:* "Top k", "k-th largest", or repeatedly taking the current smallest / largest item.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](06_heap/01_lastStoneWeight.cpp) | [1046. Last Stone Weight](https://leetcode.com/problems/last-stone-weight/) | Easy | ⬜ |
| [02](06_heap/02_kthLargestElement.cpp) | [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) | Medium | ⬜ |
| [03](06_heap/03_topKFrequentElements.cpp) | [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/) | Medium | ⬜ |
| [04](06_heap/04_taskScheduler.cpp) | [621. Task Scheduler](https://leetcode.com/problems/task-scheduler/) | Medium | ⬜ |
| [05](06_heap/05_findMedianFromDataStream.cpp) | [295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/) | Hard | ⬜ |

### Intervals: `07_intervals/`

*Reach for it when:* Ranges or time slots (meetings, bookings). Sort by start first.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](07_intervals/01_summaryRanges.cpp) | [228. Summary Ranges](https://leetcode.com/problems/summary-ranges/) | Easy | ⬜ |
| [02](07_intervals/02_insertInterval.cpp) | [57. Insert Interval](https://leetcode.com/problems/insert-interval/) | Medium | ⬜ |
| [03](07_intervals/03_nonOverlappingIntervals.cpp) | [435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) | Medium | ⬜ |
| [04](07_intervals/04_carPooling.cpp) | [1094. Car Pooling](https://leetcode.com/problems/car-pooling/) | Medium | ⬜ |
| [05](07_intervals/05_meetingRoomsIII.cpp) | [2402. Meeting Rooms III](https://leetcode.com/problems/meeting-rooms-iii/) | Hard | ⬜ |

### Greedy: `08_greedy/`

*Reach for it when:* One local choice at a time never hurts the final answer. Often needs a precompute step.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](08_greedy/01_assignCookies.cpp) | [455. Assign Cookies](https://leetcode.com/problems/assign-cookies/) | Easy | ⬜ |
| [02](08_greedy/02_jumpGame.cpp) | [55. Jump Game](https://leetcode.com/problems/jump-game/) | Medium | ⬜ |
| [03](08_greedy/03_gasStation.cpp) | [134. Gas Station](https://leetcode.com/problems/gas-station/) | Medium | ⬜ |
| [04](08_greedy/04_handOfStraights.cpp) | [846. Hand of Straights](https://leetcode.com/problems/hand-of-straights/) | Medium | ⬜ |
| [05](08_greedy/05_candy.cpp) | [135. Candy](https://leetcode.com/problems/candy/) | Hard | ⬜ |

### Monotonic stack: `09_monotonic_stack/`

*Reach for it when:* Next greater / smaller element, "how many days until…", histogram areas.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](09_monotonic_stack/01_nextGreaterElementI.cpp) | [496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/) | Easy | ⬜ |
| [02](09_monotonic_stack/02_nextGreaterElementII.cpp) | [503. Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii/) | Medium | ⬜ |
| [03](09_monotonic_stack/03_onlineStockSpan.cpp) | [901. Online Stock Span](https://leetcode.com/problems/online-stock-span/) | Medium | ⬜ |
| [04](09_monotonic_stack/04_removeKDigits.cpp) | [402. Remove K Digits](https://leetcode.com/problems/remove-k-digits/) | Medium | ⬜ |
| [05](09_monotonic_stack/05_largestRectangleInHistogram.cpp) | [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) | Hard | ⬜ |

### Grid BFS: `10_grid_bfs/`

*Reach for it when:* Minimum steps in a grid or unweighted graph, or something spreading from several sources.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](10_grid_bfs/01_floodFill.cpp) | [733. Flood Fill](https://leetcode.com/problems/flood-fill/) | Easy | ⬜ |
| [02](10_grid_bfs/02_shortestPathInBinaryMatrix.cpp) | [1091. Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/) | Medium | ⬜ |
| [03](10_grid_bfs/03_zeroOneMatrix.cpp) | [542. 01 Matrix](https://leetcode.com/problems/01-matrix/) | Medium | ⬜ |
| [04](10_grid_bfs/04_nearestExitFromEntranceInMaze.cpp) | [1926. Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/) | Medium | ⬜ |
| [05](10_grid_bfs/05_shortestPathWithObstaclesElimination.cpp) | [1293. Shortest Path in a Grid with Obstacles Elimination](https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/) | Hard | ⬜ |

### Graph DFS: `11_graph_dfs/`

*Reach for it when:* Count groups / regions / connected components, flood fill.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](11_graph_dfs/01_findIfPathExists.cpp) | [1971. Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph/) | Easy | ⬜ |
| [02](11_graph_dfs/02_maxAreaOfIsland.cpp) | [695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | Medium | ⬜ |
| [03](11_graph_dfs/03_numberOfProvinces.cpp) | [547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/) | Medium | ⬜ |
| [04](11_graph_dfs/04_pacificAtlanticWaterFlow.cpp) | [417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/) | Medium | ⬜ |
| [05](11_graph_dfs/05_longestIncreasingPathInMatrix.cpp) | [329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) | Hard | ⬜ |

### Topological sort: `12_topological_sort/`

*Reach for it when:* Dependencies, prerequisites, build order, cycle detection in a directed graph.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](12_topological_sort/01_findTheTownJudge.cpp) | [997. Find the Town Judge](https://leetcode.com/problems/find-the-town-judge/) | Easy | ⬜ |
| [02](12_topological_sort/02_courseScheduleII.cpp) | [210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) | Medium | ⬜ |
| [03](12_topological_sort/03_findEventualSafeStates.cpp) | [802. Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/) | Medium | ⬜ |
| [04](12_topological_sort/04_courseScheduleIV.cpp) | [1462. Course Schedule IV](https://leetcode.com/problems/course-schedule-iv/) | Medium | ⬜ |
| [05](12_topological_sort/05_parallelCoursesIII.cpp) | [2050. Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/) | Hard | ⬜ |

### DP (1D): `13_dp_1d/`

*Reach for it when:* Min / max / number of ways to reach a target, where greedy can be wrong.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](13_dp_1d/01_climbingStairs.cpp) | [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | Easy | ⬜ |
| [02](13_dp_1d/02_houseRobber.cpp) | [198. House Robber](https://leetcode.com/problems/house-robber/) | Medium | ⬜ |
| [03](13_dp_1d/03_wordBreak.cpp) | [139. Word Break](https://leetcode.com/problems/word-break/) | Medium | ⬜ |
| [04](13_dp_1d/04_longestIncreasingSubsequence.cpp) | [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | Medium | ⬜ |
| [05](13_dp_1d/05_longestValidParentheses.cpp) | [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/) | Hard | ⬜ |

### DP (2D): `14_dp_2d/`

*Reach for it when:* Two strings or arrays compared position by position, or paths in a grid.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](14_dp_2d/01_pascalsTriangle.cpp) | [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/) | Easy | ⬜ |
| [02](14_dp_2d/02_uniquePaths.cpp) | [62. Unique Paths](https://leetcode.com/problems/unique-paths/) | Medium | ⬜ |
| [03](14_dp_2d/03_maximalSquare.cpp) | [221. Maximal Square](https://leetcode.com/problems/maximal-square/) | Medium | ⬜ |
| [04](14_dp_2d/04_editDistance.cpp) | [72. Edit Distance](https://leetcode.com/problems/edit-distance/) | Medium | ⬜ |
| [05](14_dp_2d/05_regularExpressionMatching.cpp) | [10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/) | Hard | ⬜ |

### Trie: `15_trie/`

*Reach for it when:* Many "starts with" queries over a fixed set of words (autocomplete).

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](15_trie/01_longestCommonPrefix.cpp) | [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) | Easy | ⬜ |
| [02](15_trie/02_implementTrie.cpp) | [208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/) | Medium | ⬜ |
| [03](15_trie/03_addAndSearchWords.cpp) | [211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/) | Medium | ⬜ |
| [04](15_trie/04_replaceWords.cpp) | [648. Replace Words](https://leetcode.com/problems/replace-words/) | Medium | ⬜ |
| [05](15_trie/05_wordSearchII.cpp) | [212. Word Search II](https://leetcode.com/problems/word-search-ii/) | Hard | ⬜ |

### Design: `16_design/`

*Reach for it when:* "Implement a class where every operation is O(1)": usually two data structures together.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](16_design/01_designHashSet.cpp) | [705. Design HashSet](https://leetcode.com/problems/design-hashset/) | Easy | ⬜ |
| [02](16_design/02_minStack.cpp) | [155. Min Stack](https://leetcode.com/problems/min-stack/) | Medium | ⬜ |
| [03](16_design/03_insertDeleteGetRandom.cpp) | [380. Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/) | Medium | ⬜ |
| [04](16_design/04_timeBasedKeyValueStore.cpp) | [981. Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/) | Medium | ⬜ |
| [05](16_design/05_lfuCache.cpp) | [460. LFU Cache](https://leetcode.com/problems/lfu-cache/) | Hard | ⬜ |

### Linked list: `17_linked_list/`

*Reach for it when:* Reversing, merging, finding the middle or a cycle: slow and fast pointers, and a dummy head node.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](17_linked_list/01_reverseLinkedList.cpp) | [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) | Easy | ⬜ |
| [02](17_linked_list/02_linkedListCycle.cpp) | [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/) | Easy | ⬜ |
| [03](17_linked_list/03_addTwoNumbers.cpp) | [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | Medium | ⬜ |
| [04](17_linked_list/04_reorderList.cpp) | [143. Reorder List](https://leetcode.com/problems/reorder-list/) | Medium | ⬜ |
| [05](17_linked_list/05_mergeKSortedLists.cpp) | [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/) | Hard | ⬜ |

### Binary tree: `18_binary_tree/`

*Reach for it when:* Anything on a tree: recursion that returns something from each subtree (depth, sum, a flag), or BFS for level-by-level questions.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](18_binary_tree/01_maximumDepth.cpp) | [104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | Easy | ⬜ |
| [02](18_binary_tree/02_levelOrderTraversal.cpp) | [102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) | Medium | ⬜ |
| [03](18_binary_tree/03_validateBST.cpp) | [98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) | Medium | ⬜ |
| [04](18_binary_tree/04_lowestCommonAncestor.cpp) | [236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | Medium | ⬜ |
| [05](18_binary_tree/05_maximumPathSum.cpp) | [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | Hard | ⬜ |

### Backtracking: `19_backtracking/`

*Reach for it when:* List all the subsets, permutations, combinations or placements: choose, recurse, undo the choice.

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](19_backtracking/01_subsets.cpp) | [78. Subsets](https://leetcode.com/problems/subsets/) | Medium | ⬜ |
| [02](19_backtracking/02_permutations.cpp) | [46. Permutations](https://leetcode.com/problems/permutations/) | Medium | ⬜ |
| [03](19_backtracking/03_combinationSum.cpp) | [39. Combination Sum](https://leetcode.com/problems/combination-sum/) | Medium | ⬜ |
| [04](19_backtracking/04_wordSearch.cpp) | [79. Word Search](https://leetcode.com/problems/word-search/) | Medium | ⬜ |
| [05](19_backtracking/05_nQueens.cpp) | [51. N-Queens](https://leetcode.com/problems/n-queens/) | Hard | ⬜ |

### Shortest paths & union-find: `20_shortest_path_union_find/`

*Reach for it when:* Weighted shortest paths (Dijkstra, or Bellman-Ford when the number of steps is limited), minimum spanning trees, and "are these connected?" (union-find).

| # | Problem | Difficulty | Status |
|---|---------|------------|--------|
| [01](20_shortest_path_union_find/01_redundantConnection.cpp) | [684. Redundant Connection](https://leetcode.com/problems/redundant-connection/) | Medium | ⬜ |
| [02](20_shortest_path_union_find/02_networkDelayTime.cpp) | [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/) | Medium | ⬜ |
| [03](20_shortest_path_union_find/03_cheapestFlightsWithinKStops.cpp) | [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) | Medium | ⬜ |
| [04](20_shortest_path_union_find/04_minCostToConnectAllPoints.cpp) | [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) | Medium | ⬜ |
| [05](20_shortest_path_union_find/05_swimInRisingWater.cpp) | [778. Swim in Rising Water](https://leetcode.com/problems/swim-in-rising-water/) | Hard | ⬜ |

## Spotting the pattern

| Pattern | Reach for it when… |
|---------|--------------------|
| Hashing | You keep asking "is X in the input?" and need the answer in O(1). |
| Two pointers | You pick a pair (i, j) and comparing the two ends rules one of them out. Common on sorted arrays. |
| Sliding window | Longest / shortest contiguous subarray or substring that satisfies a condition. |
| Prefix sum | Count or find subarrays with sum exactly X, especially when values can be negative. |
| Binary search | A sorted array, or "minimum X such that it's possible" where any bigger X also works (capacity, speed, time). |
| Heap / top K | "Top k", "k-th largest", or repeatedly taking the current smallest / largest item. |
| Intervals | Ranges or time slots (meetings, bookings). Sort by start first. |
| Greedy | One local choice at a time never hurts the final answer. Often needs a precompute step. |
| Monotonic stack | Next greater / smaller element, "how many days until…", histogram areas. |
| Grid BFS | Minimum steps in a grid or unweighted graph, or something spreading from several sources. |
| Graph DFS | Count groups / regions / connected components, flood fill. |
| Topological sort | Dependencies, prerequisites, build order, cycle detection in a directed graph. |
| DP (1D) | Min / max / number of ways to reach a target, where greedy can be wrong. |
| DP (2D) | Two strings or arrays compared position by position, or paths in a grid. |
| Trie | Many "starts with" queries over a fixed set of words (autocomplete). |
| Design | "Implement a class where every operation is O(1)": usually two data structures together. |
| Linked list | Reversing, merging, finding the middle or a cycle: slow and fast pointers, and a dummy head node. |
| Binary tree | Anything on a tree: recursion that returns something from each subtree (depth, sum, a flag), or BFS for level-by-level questions. |
| Backtracking | List all the subsets, permutations, combinations or placements: choose, recurse, undo the choice. |
| Shortest paths & union-find | Weighted shortest paths (Dijkstra, or Bellman-Ford when the number of steps is limited), minimum spanning trees, and "are these connected?" (union-find). |
