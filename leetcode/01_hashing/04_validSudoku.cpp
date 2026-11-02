/*
 * Valid Sudoku
 * LeetCode 36 (Medium) - https://leetcode.com/problems/valid-sudoku/
 *
 * You are given a 9 x 9 Sudoku board that may be partly filled in. Empty cells
 * are '.'. Return true if the filled-in cells break none of the rules:
 *   - each row contains each digit 1-9 at most once,
 *   - each column contains each digit 1-9 at most once,
 *   - each of the nine 3 x 3 boxes contains each digit 1-9 at most once.
 *
 * You only check the cells that are filled in. A board can be valid even if
 * it can't be solved.
 *
 * Example 1:
 *   Input:  5 3 . | . 7 . | . . .
 *           6 . . | 1 9 5 | . . .
 *           . 9 8 | . . . | . 6 .
 *           ------+-------+------
 *           8 . . | . 6 . | . . 3
 *           4 . . | 8 . 3 | . . 1
 *           7 . . | . 2 . | . . 6
 *           ------+-------+------
 *           . 6 . | . . . | 2 8 .
 *           . . . | 4 1 9 | . . 5
 *           . . . | . 8 . | . 7 9
 *   Output: true
 *
 * Example 2:
 *   Input:  the same board, but with the top-left 5 replaced by an 8
 *   Output: false
 *   Why:    the top-left box now contains two 8s.
 *
 * Constraints:
 *   board is 9 x 9, and every cell is a digit '1'-'9' or '.'.
 *
 * Target: one pass over the board.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_validSudoku.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    // Boards are written as 9 rows of text and converted to vector<vector<char>>.
    struct Case { vector<string> rows; bool expected; };
    vector<Case> cases = {
        {{"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
          "7...2...6", ".6....28.", "...419..5", "....8..79"}, true},
        {{"83..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
          "7...2...6", ".6....28.", "...419..5", "....8..79"}, false},
        {{".........", ".........", ".........", ".........", ".........",
          ".........", ".........", ".........", "........."}, true},
        {{"11.......", ".........", ".........", ".........", ".........",
          ".........", ".........", ".........", "........."}, false},   // same row
        {{"5........", ".........", ".........", ".........", ".........",
          ".........", ".........", ".........", "5........"}, false},   // same column
        {{"1........", ".1.......", ".........", ".........", ".........",
          ".........", ".........", ".........", "........."}, false},   // same box only
        {{"534678912", "672195348", "198342567", "859761423", "426853791",
          "713924856", "961537284", "287419635", "345286179"}, true},   // a solved board
        {{"....5....", ".........", ".........", ".........", ".........",
          ".........", ".........", ".........", "....5...."}, false},   // middle column
    };
    for (auto& c : cases) {
        vector<vector<char>> board;
        for (auto& row : c.rows) board.emplace_back(row.begin(), row.end());
        check(sol.isValidSudoku(board), c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
