/*
 * 07 - INTERVALS: Merge Intervals
 * LeetCode 56 (Medium) - https://leetcode.com/problems/merge-intervals/
 *
 * You are given an array `intervals` where intervals[i] = [start_i, end_i].
 * Merge every group of overlapping intervals, and return an array of
 * non-overlapping intervals that covers exactly the same ranges as the input.
 *
 * Intervals that only touch, like [1, 4] and [4, 5], also count as overlapping.
 * You can return the result in any order.
 *
 * Example 1:
 *   Input:  intervals = [[1, 3], [2, 6], [8, 10], [15, 18]]
 *   Output: [[1, 6], [8, 10], [15, 18]]
 *   Why:    [1, 3] and [2, 6] overlap, so they become [1, 6].
 *
 * Example 2:
 *   Input:  intervals = [[1, 4], [4, 5]]
 *   Output: [[1, 5]]
 *
 * Example 3:
 *   Input:  intervals = [[4, 7], [1, 4]]
 *   Output: [[1, 7]]
 *   Why:    the input is not necessarily sorted.
 *
 * Constraints:
 *   1 <= intervals.length <= 10^4
 *   intervals[i].length == 2
 *   0 <= start_i <= end_i <= 10^4
 *
 * Target: O(n log n) time.
 *
 * How to spot this pattern: anything with ranges or time slots (meetings,
 * bookings, delivery windows). Sorting by start is almost always step one.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 07_intervals_mergeIntervals.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { vector<vector<int>> intervals; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},
        {{{1, 4}, {4, 5}}, {{1, 5}}},
        {{{4, 7}, {1, 4}}, {{1, 7}}},
        {{{1, 10}, {2, 3}, {4, 5}}, {{1, 10}}},
        {{{5, 5}}, {{5, 5}}},
        {{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}}, {{1, 10}}},
        {{{1, 4}, {0, 0}}, {{0, 0}, {1, 4}}},
    };
    for (auto& c : cases) {
        // Any order is accepted, so sort the result before comparing.
        auto got = sol.merge(c.intervals);
        sort(got.begin(), got.end());
        check(got, c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
