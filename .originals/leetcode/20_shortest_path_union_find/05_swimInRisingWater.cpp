/*
 * Swim in Rising Water
 * LeetCode 778 (Hard) - https://leetcode.com/problems/swim-in-rising-water/
 *
 * You are given an n x n grid where grid[r][c] is the elevation of cell
 * (r, c). It starts raining: at time t, the water everywhere is t deep.
 *
 * You can swim from a cell to a neighbouring one (up, down, left or right)
 * when both cells' elevations are at most t, and swimming takes no time.
 * Starting at the top-left cell, return the earliest time t at which you can
 * reach the bottom-right cell.
 *
 * Example 1:
 *   Input:  grid = [[0, 2],
 *                   [1, 3]]
 *   Output: 3
 *   Why:    the bottom-right cell itself has elevation 3.
 *
 * Example 2:
 *   Input:  grid = [[ 0,  1,  2,  3,  4],
 *                   [24, 23, 22, 21,  5],
 *                   [12, 13, 14, 15, 16],
 *                   [11, 17, 18, 19, 20],
 *                   [10,  9,  8,  7,  6]]
 *   Output: 16
 *
 * Constraints:
 *   1 <= n <= 50
 *   The values are all of 0, 1, ..., n^2 - 1, each exactly once.
 *
 * Target: O(n^2 log n). The answer is the smallest possible "highest
 * elevation on a path". Three ways to get it: Dijkstra where a path's cost is
 * its maximum instead of its sum; binary search on t with a BFS for each
 * guess; or union-find, adding cells from lowest to highest until the two
 * corners join.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_swimInRisingWater.cpp && ./a.out
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

    struct Case { vector<vector<int>> grid; int expected; };
    vector<Case> cases = {
        {{{0, 2}, {1, 3}}, 3},
        {{{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}}, 16},
        {{{0}}, 0},
        {{{3, 2}, {0, 1}}, 3},          // you have to wait at the start
        {{{0, 1, 2}, {7, 8, 3}, {6, 5, 4}}, 4},
        {{{0, 8, 7}, {1, 6, 5}, {2, 3, 4}}, 4},
    };
    for (auto& c : cases) check(sol.swimInWater(c.grid), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
