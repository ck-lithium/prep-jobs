/*
 * Maximal Square
 * LeetCode 221 (Medium) - https://leetcode.com/problems/maximal-square/
 *
 * Given a grid of '0' and '1' characters, return the area of the largest
 * square made only of '1's.
 *
 * Example 1:
 *   Input:  1 0 1 0 0
 *           1 0 1 1 1
 *           1 1 1 1 1
 *           1 0 0 1 0
 *   Output: 4
 *   Why:    the 2 x 2 square in rows 1-2, columns 2-3 (or 3-4).
 *
 * Example 2:
 *   Input:  0 1
 *           1 0
 *   Output: 1
 *
 * Example 3:
 *   Input:  0
 *   Output: 0
 *
 * Constraints:
 *   1 <= rows, cols <= 300
 *   Each cell is '0' or '1'.
 *
 * Target: O(rows * cols). side[r][c] = side of the largest all-'1' square
 * whose bottom-right corner is (r, c). It's limited by the squares ending just
 * above, just to the left and diagonally up-left.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_maximalSquare.cpp && ./a.out
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

    // Grids are written as rows of text and converted to vector<vector<char>>.
    struct Case { vector<string> rows; int expected; };
    vector<Case> cases = {
        {{"10100", "10111", "11111", "10010"}, 4},
        {{"01", "10"}, 1},
        {{"0"}, 0},
        {{"1"}, 1},
        {{"11", "11"}, 4},
        {{"111", "111", "111"}, 9},
        {{"1101", "1111", "0111"}, 4},
        {{"0000", "0110", "0110"}, 4},
    };
    for (auto& c : cases) {
        vector<vector<char>> matrix;
        for (auto& row : c.rows) matrix.emplace_back(row.begin(), row.end());
        check(sol.maximalSquare(matrix), c.expected);
    }

    // Big input: a 300 x 300 grid of '1's.
    vector<vector<char>> big(300, vector<char>(300, '1'));
    check(sol.maximalSquare(big), 90000);

    cout << passed << "/" << total << " tests passed\n";
}
