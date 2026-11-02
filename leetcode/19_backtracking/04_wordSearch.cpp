/*
 * Word Search
 * LeetCode 79 (Medium) - https://leetcode.com/problems/word-search/
 *
 * Given a grid of letters and a word, return true if the word can be spelled
 * by a path through the grid. The path moves up, down, left or right between
 * neighbouring cells and can't use the same cell twice.
 *
 * Example 1:
 *   Input:  board = [A B C E
 *                    S F C S
 *                    A D E E], word = "ABCCED"
 *   Output: true
 *
 * Example 2:
 *   Input:  the same board, word = "SEE"
 *   Output: true
 *
 * Example 3:
 *   Input:  the same board, word = "ABCB"
 *   Output: false
 *   Why:    the path would need the B cell twice.
 *
 * Constraints:
 *   1 <= rows, cols <= 6
 *   1 <= word.length <= 15
 *   The board and the word contain only English letters (upper and lower case).
 *
 * Target: backtracking from every cell. Mark a cell as used before going
 * deeper and unmark it when you come back. (This is the one-word version of
 * Word Search II in the trie folder.)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_wordSearch.cpp && ./a.out
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

    // Boards are written as rows of text and converted to vector<vector<char>>.
    vector<string> example = {"ABCE", "SFCS", "ADEE"};
    struct Case { vector<string> rows; string word; bool expected; };
    vector<Case> cases = {
        {example, "ABCCED", true},
        {example, "SEE", true},
        {example, "ABCB", false},
        {{"a"}, "a", true},
        {{"a"}, "b", false},
        {{"ab"}, "ba", true},
        {{"aa"}, "aaa", false},
        {{"ab", "cd"}, "acdb", true},
        {{"CAA", "AAA", "BCD"}, "AAB", true},
        {example, "ABCESEEDASFC", true},     // uses all 12 cells
    };
    for (auto& c : cases) {
        vector<vector<char>> board;
        for (auto& row : c.rows) board.emplace_back(row.begin(), row.end());
        check(sol.exist(board, c.word), c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
