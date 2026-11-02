/*
 * Max Area of Island
 * LeetCode 695 (Medium) - https://leetcode.com/problems/max-area-of-island/
 *
 * You are given a grid of 0s (water) and 1s (land). An island is a group of 1s
 * connected up, down, left or right (not diagonally), and its area is the
 * number of cells in it. Return the largest island's area, or 0 if there is no
 * land.
 *
 * Example 1:
 *   Input:  0 0 1 0 0 0 0 1 0 0 0 0 0
 *           0 0 0 0 0 0 0 1 1 1 0 0 0
 *           0 1 1 0 1 0 0 0 0 0 0 0 0
 *           0 1 0 0 1 1 0 0 1 0 1 0 0
 *           0 1 0 0 1 1 0 0 1 1 1 0 0
 *           0 0 0 0 0 0 0 0 0 0 1 0 0
 *           0 0 0 0 0 0 0 1 1 1 0 0 0
 *           0 0 0 0 0 0 0 1 1 0 0 0 0
 *   Output: 6
 *   Why:    the island in the middle right (rows 3-5, columns 8-10).
 *
 * Example 2:
 *   Input:  0 0 0 0 0 0 0 0
 *   Output: 0
 *
 * Constraints:
 *   1 <= rows, cols <= 50
 *   grid[i][j] is 0 or 1.
 *
 * Target: O(rows * cols). It's "Number of Islands" from the initial set, but
 * each search returns the size of what it found.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_maxAreaOfIsland.cpp && ./a.out
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

    // Grids are written as rows of text and converted to vector<vector<int>>.
    struct Case { vector<string> rows; int expected; };
    vector<Case> cases = {
        {{"0010000100000", "0000000111000", "0110100000000", "0100110010100",
          "0100110011100", "0000000000100", "0000000111000", "0000000110000"}, 6},
        {{"00000000"}, 0},
        {{"1"}, 1},
        {{"11", "10"}, 3},
        {{"10", "01"}, 1},
        {{"1101", "0101", "1101"}, 5},
    };
    for (auto& c : cases) {
        vector<vector<int>> grid;
        for (auto& row : c.rows) {
            grid.emplace_back();
            for (char ch : row) grid.back().push_back(ch - '0');
        }
        check(sol.maxAreaOfIsland(grid), c.expected);
    }

    // Big input: a 50 x 50 grid of land.
    vector<vector<int>> big(50, vector<int>(50, 1));
    check(sol.maxAreaOfIsland(big), 2500);

    cout << passed << "/" << total << " tests passed\n";
}
