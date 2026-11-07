/*
 * Shortest Path in a Grid with Obstacles Elimination
 * LeetCode 1293 (Hard) - https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
 *
 * You are given a grid of 0s (empty) and 1s (obstacles). You can step up,
 * down, left or right onto any cell, but you may walk through at most `k`
 * obstacles in total (as if you removed them).
 *
 * Return the minimum number of steps from the top-left cell to the
 * bottom-right cell, or -1 if it's impossible.
 *
 * Example 1:
 *   Input:  grid = [[0, 0, 0],
 *                   [1, 1, 0],
 *                   [0, 0, 0],
 *                   [0, 1, 1],
 *                   [0, 0, 0]], k = 1
 *   Output: 6
 *   Why:    without removing anything it takes 10 steps; removing the
 *           obstacle at (3, 2) gives a 6-step path down the right side.
 *
 * Example 2:
 *   Input:  grid = [[0, 1, 1],
 *                   [1, 1, 1],
 *                   [1, 0, 0]], k = 1
 *   Output: -1
 *   Why:    every path crosses at least 2 obstacles.
 *
 * Constraints:
 *   1 <= rows, cols <= 40
 *   1 <= k <= rows * cols
 *   grid[i][j] is 0 or 1, and the two corners are 0.
 *
 * Target: BFS over states (row, col, obstacles left): O(rows * cols * k).
 * Visiting the same cell again is fine if you get there with more removals
 * left than before.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_shortestPathWithObstaclesElimination.cpp && ./a.out
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

    struct Case { vector<vector<int>> grid; int k; int expected; };
    vector<Case> cases = {
        {{{0, 0, 0}, {1, 1, 0}, {0, 0, 0}, {0, 1, 1}, {0, 0, 0}}, 1, 6},
        {{{0, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 1, -1},
        {{{0}}, 1, 0},
        {{{0, 1}, {1, 0}}, 1, 2},
        {{{0, 0}, {0, 0}}, 1, 2},
        {{{0, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 2, 4},
        {{{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}}, 1, 6},  // remove (2, 3)
    };
    for (auto& c : cases) check(sol.shortestPath(c.grid, c.k), c.expected);

    // Big input: 40 x 40 obstacles (except the corners) and k = 1600: the
    // straight-line distance, 78 steps.
    vector<vector<int>> big(40, vector<int>(40, 1));
    big[0][0] = big[39][39] = 0;
    check(sol.shortestPath(big, 1600), 78);

    cout << passed << "/" << total << " tests passed\n";
}
