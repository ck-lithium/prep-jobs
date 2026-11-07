/*
 * Unique Paths
 * LeetCode 62 (Medium) - https://leetcode.com/problems/unique-paths/
 *
 * A robot starts in the top-left cell of an m x n grid and wants to reach the
 * bottom-right cell. It can only move right or down. How many different paths
 * are there?
 *
 * Example 1:
 *   Input:  m = 3, n = 7
 *   Output: 28
 *
 * Example 2:
 *   Input:  m = 3, n = 2
 *   Output: 3
 *   Why:    right-down-down, down-right-down, down-down-right.
 *
 * Constraints:
 *   1 <= m, n <= 100
 *   The answer is at most 2 * 10^9.
 *
 * Target: O(m * n) time, O(n) space. paths(r, c) = paths(r - 1, c) +
 * paths(r, c - 1). (It's also the binomial coefficient C(m + n - 2, m - 1),
 * but computing that with factorials overflows long before the answer does.)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_uniquePaths.cpp && ./a.out
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

    struct Case { int m, n; int expected; };
    vector<Case> cases = {
        {3, 7, 28},
        {3, 2, 3},
        {1, 1, 1},
        {1, 10, 1},
        {2, 2, 2},
        {3, 3, 6},
        {10, 10, 48620},
        {23, 12, 193536720},
        {51, 9, 1916797311},   // close to INT_MAX: a factorial formula overflows here
    };
    for (auto& c : cases) check(sol.uniquePaths(c.m, c.n), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
