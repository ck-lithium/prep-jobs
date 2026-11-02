/*
 * Insert Interval
 * LeetCode 57 (Medium) - https://leetcode.com/problems/insert-interval/
 *
 * You are given a list of non-overlapping intervals [start, end], sorted by
 * start, and one more interval `newInterval`. Insert `newInterval` so the list
 * stays sorted and non-overlapping, merging intervals where needed, and
 * return the result.
 *
 * Intervals that only touch, like [1, 5] and [5, 7], count as overlapping.
 *
 * Example 1:
 *   Input:  intervals = [[1, 3], [6, 9]], newInterval = [2, 5]
 *   Output: [[1, 5], [6, 9]]
 *
 * Example 2:
 *   Input:  intervals = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval = [4, 8]
 *   Output: [[1, 2], [3, 10], [12, 16]]
 *   Why:    [4, 8] overlaps [3, 5], [6, 7] and [8, 10].
 *
 * Constraints:
 *   0 <= intervals.length <= 10^4
 *   0 <= start <= end <= 10^5
 *   intervals is sorted by start and has no overlaps.
 *
 * Target: O(n), one pass. The input is already sorted, so you don't need to
 * sort again: copy what ends before newInterval, merge what overlaps it, copy
 * the rest.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_insertInterval.cpp && ./a.out
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

    struct Case { vector<vector<int>> intervals; vector<int> newInterval; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{1, 3}, {6, 9}}, {2, 5}, {{1, 5}, {6, 9}}},
        {{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}}, {4, 8}, {{1, 2}, {3, 10}, {12, 16}}},
        {{}, {5, 7}, {{5, 7}}},
        {{{1, 5}}, {2, 3}, {{1, 5}}},
        {{{1, 5}}, {6, 8}, {{1, 5}, {6, 8}}},
        {{{1, 5}}, {0, 0}, {{0, 0}, {1, 5}}},
        {{{3, 5}, {12, 15}}, {6, 6}, {{3, 5}, {6, 6}, {12, 15}}},
        {{{1, 5}}, {5, 7}, {{1, 7}}},
        {{{1, 2}, {3, 4}}, {0, 10}, {{0, 10}}},
    };
    for (auto& c : cases) check(sol.insert(c.intervals, c.newInterval), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
