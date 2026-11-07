/*
 * N-Queens
 * LeetCode 51 (Hard) - https://leetcode.com/problems/n-queens/
 *
 * Place n queens on an n x n chessboard so that no two attack each other: no
 * two share a row, a column or a diagonal. Return every solution, in any
 * order. Write each solution as n strings, one per row, with 'Q' for a queen
 * and '.' for an empty square.
 *
 * Example 1:
 *   Input:  n = 4
 *   Output: [[".Q..",     [["..Q.",
 *             "...Q",       "Q...",
 *             "Q...",       "...Q",
 *             "..Q."],      ".Q.."]]
 *
 * Example 2:
 *   Input:  n = 1
 *   Output: [["Q"]]
 *
 * Constraints:
 *   1 <= n <= 9
 *
 * Target: place one queen per row, and keep three sets of what's taken:
 * columns, "down" diagonals (row - col) and "up" diagonals (row + col). Each
 * check is then O(1).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_nQueens.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(const string& s) { return '"' + s + '"'; }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

// True if the board is n x n, has n queens and no two attack each other.
bool validBoard(const vector<string>& board, int n) {
    if ((int)board.size() != n) return false;
    vector<pair<int, int>> queens;
    for (int r = 0; r < n; r++) {
        if ((int)board[r].size() != n) return false;
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 'Q') queens.push_back({r, c});
            else if (board[r][c] != '.') return false;
        }
    }
    if ((int)queens.size() != n) return false;
    for (size_t i = 0; i < queens.size(); i++)
        for (size_t j = i + 1; j < queens.size(); j++) {
            auto [r1, c1] = queens[i];
            auto [r2, c2] = queens[j];
            if (r1 == r2 || c1 == c2 || abs(r1 - r2) == abs(c1 - c2)) return false;
        }
    return true;
}

// Checks every board and counts the different ones.
string summary(vector<vector<string>> boards, int n) {
    for (auto& b : boards)
        if (!validBoard(b, n)) return "an invalid board: " + str(b);
    sort(boards.begin(), boards.end());
    boards.erase(unique(boards.begin(), boards.end()), boards.end());
    return to_string(boards.size()) + " different valid boards";
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

    // n = 4, compared exactly (sorted, since any order is accepted).
    auto four = sol.solveNQueens(4);
    sort(four.begin(), four.end());
    check(four, vector<vector<string>>{{"..Q.", "Q...", "...Q", ".Q.."}, {".Q..", "...Q", "Q...", "..Q."}});
    check(sol.solveNQueens(1), vector<vector<string>>{{"Q"}});

    // Other sizes: every board must be valid, and the counts must match.
    vector<pair<int, int>> counts = {{2, 0}, {3, 0}, {5, 10}, {6, 4}, {8, 92}, {9, 352}};
    for (auto [n, count] : counts)
        check(summary(sol.solveNQueens(n), n), to_string(count) + " different valid boards");

    cout << passed << "/" << total << " tests passed\n";
}
