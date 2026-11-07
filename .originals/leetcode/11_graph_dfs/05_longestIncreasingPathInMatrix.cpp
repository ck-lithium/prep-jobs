/*
 * Longest Increasing Path in a Matrix
 * LeetCode 329 (Hard) - https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 *
 * Given a matrix of integers, return the length of the longest path that only
 * moves up, down, left or right (no diagonals, no wrapping around) and in
 * which every step goes to a strictly larger value.
 *
 * Example 1:
 *   Input:  [[9, 9, 4],
 *            [6, 6, 8],
 *            [2, 1, 1]]
 *   Output: 4
 *   Why:    1 -> 2 -> 6 -> 9.
 *
 * Example 2:
 *   Input:  [[3, 4, 5],
 *            [3, 2, 6],
 *            [2, 2, 1]]
 *   Output: 4
 *   Why:    3 -> 4 -> 5 -> 6.
 *
 * Example 3:
 *   Input:  [[1]]
 *   Output: 1
 *
 * Constraints:
 *   1 <= rows, cols <= 200
 *   0 <= matrix[i][j] <= 2^31 - 1
 *
 * Target: O(rows * cols). DFS from every cell, but remember the answer for
 * each cell once you have it (memoisation): the longest path starting at a
 * cell never changes. No "visited" set is needed, since a strictly increasing
 * path can't loop.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_longestIncreasingPathInMatrix.cpp && ./a.out
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

    struct Case { vector<vector<int>> matrix; int expected; };
    vector<Case> cases = {
        {{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}}, 4},
        {{{3, 4, 5}, {3, 2, 6}, {2, 2, 1}}, 4},
        {{{1}}, 1},
        {{{1, 2}}, 2},
        {{{7, 7}, {7, 7}}, 1},
        {{{1, 2, 3}, {6, 5, 4}, {7, 8, 9}}, 9},
        {{{2147483647, 1}}, 2},
    };
    for (auto& c : cases) check(sol.longestIncreasingPath(c.matrix), c.expected);

    // Big input: 200 x 200 numbered 0, 1, 2, ... along a snake (left to right,
    // then right to left on the next row, and so on). The snake visits every
    // cell in increasing order, so the answer is 40000. Without memoisation
    // this takes forever.
    vector<vector<int>> big(200, vector<int>(200));
    for (int r = 0; r < 200; r++)
        for (int c = 0; c < 200; c++) big[r][c] = r * 200 + (r % 2 == 0 ? c : 199 - c);
    check(sol.longestIncreasingPath(big), 40000);

    cout << passed << "/" << total << " tests passed\n";
}
