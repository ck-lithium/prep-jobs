/*
 * Non-overlapping Intervals
 * LeetCode 435 (Medium) - https://leetcode.com/problems/non-overlapping-intervals/
 *
 * Given a list of intervals [start, end], return the minimum number of
 * intervals you need to remove so that the rest don't overlap.
 *
 * Here intervals that only touch, like [1, 2] and [2, 3], do NOT overlap.
 *
 * Example 1:
 *   Input:  intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
 *   Output: 1
 *   Why:    remove [1, 3].
 *
 * Example 2:
 *   Input:  intervals = [[1, 2], [1, 2], [1, 2]]
 *   Output: 2
 *
 * Example 3:
 *   Input:  intervals = [[1, 2], [2, 3]]
 *   Output: 0
 *
 * Constraints:
 *   1 <= intervals.length <= 10^5
 *   -5 * 10^4 <= start < end <= 5 * 10^4
 *
 * Target: O(n log n). Turn it around: keep as many intervals as possible.
 * Which interval is always safe to keep first?
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_nonOverlappingIntervals.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { vector<vector<int>> intervals; int expected; };
    vector<Case> cases = {
        {{{1, 2}, {2, 3}, {3, 4}, {1, 3}}, 1},
        {{{1, 2}, {1, 2}, {1, 2}}, 2},
        {{{1, 2}, {2, 3}}, 0},
        {{{0, 2}, {1, 3}, {2, 4}, {3, 5}, {4, 6}}, 2},
        {{{1, 100}, {11, 22}, {1, 11}, {2, 12}}, 2},
        {{{-5, -1}, {-3, 0}}, 1},
        {{{1, 2}}, 0},
    };
    for (auto& c : cases) check(sol.eraseOverlapIntervals(c.intervals), c.expected);

    // Big input: [s, s + 2] for every s from -50000 to 49997 (99998 intervals).
    // At most 49999 of them fit side by side, so 49999 must go.
    vector<vector<int>> big;
    for (int s = -50000; s <= 49997; s++) big.push_back({s, s + 2});
    check(sol.eraseOverlapIntervals(big), 49999);

    cout << passed << "/" << total << " tests passed\n";
}
