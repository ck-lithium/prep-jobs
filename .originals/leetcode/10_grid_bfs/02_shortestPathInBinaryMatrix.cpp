/*
 * Shortest Path in Binary Matrix
 * LeetCode 1091 (Medium) - https://leetcode.com/problems/shortest-path-in-binary-matrix/
 *
 * You are given an n x n grid of 0s (open) and 1s (blocked). Find the shortest
 * path from the top-left cell to the bottom-right cell that only visits 0
 * cells. You can move to any of the 8 neighbouring cells, diagonals included.
 *
 * Return the length of that path, counted as the number of cells visited
 * (start and end included), or -1 if there is no such path.
 *
 * Example 1:
 *   Input:  grid = [[0, 1],
 *                   [1, 0]]
 *   Output: 2
 *   Why:    one diagonal step.
 *
 * Example 2:
 *   Input:  grid = [[0, 0, 0],
 *                   [1, 1, 0],
 *                   [1, 1, 0]]
 *   Output: 4
 *
 * Example 3:
 *   Input:  grid = [[1, 0, 0],
 *                   [1, 1, 0],
 *                   [1, 1, 0]]
 *   Output: -1
 *   Why:    the start cell itself is blocked.
 *
 * Constraints:
 *   1 <= n <= 100
 *   grid[i][j] is 0 or 1.
 *
 * Target: O(n^2) with BFS.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_shortestPathInBinaryMatrix.cpp && ./a.out
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
        {{{0, 1}, {1, 0}}, 2},
        {{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}}, 4},
        {{{1, 0, 0}, {1, 1, 0}, {1, 1, 0}}, -1},
        {{{0}}, 1},
        {{{1}}, -1},
        {{{0, 0}, {0, 1}}, -1},
        {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 3},
        {{{0, 1, 1, 0, 0, 0},
          {0, 1, 0, 1, 1, 0},
          {0, 1, 1, 0, 1, 0},
          {0, 0, 0, 1, 1, 0},
          {1, 1, 1, 1, 1, 0},
          {1, 1, 1, 1, 1, 0}}, 14},
    };
    for (auto& c : cases) check(sol.shortestPathBinaryMatrix(c.grid), c.expected);

    // Big input: a 100 x 100 open grid. The diagonal is the shortest path.
    vector<vector<int>> big(100, vector<int>(100, 0));
    check(sol.shortestPathBinaryMatrix(big), 100);

    cout << passed << "/" << total << " tests passed\n";
}
