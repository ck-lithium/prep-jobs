/*
 * 11 - GRAPH DFS: Number of Islands
 * LeetCode 200 (Medium) - https://leetcode.com/problems/number-of-islands/
 *
 * You are given an m x n grid of characters, where '1' is land and '0' is
 * water. Return the number of islands.
 *
 * An island is a group of land cells connected horizontally or vertically (not
 * diagonally). Everything outside the grid counts as water.
 *
 * Example 1:
 *   Input:  grid = ["11110",
 *                   "11010",
 *                   "11000",
 *                   "00000"]
 *   Output: 1
 *
 * Example 2:
 *   Input:  grid = ["11000",
 *                   "11000",
 *                   "00100",
 *                   "00011"]
 *   Output: 3
 *
 * Constraints:
 *   1 <= m, n <= 300
 *   grid[i][j] is '0' or '1'.
 *
 * Target: O(m * n) time.
 *
 * How to spot this pattern: "count the groups / regions / clusters", flood fill,
 * "how many connected components". BFS or union-find also work here.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void sink(vector<vector<char>>& grid, int r0, int c0) {

        const int rows = grid.size(), cols = grid[0].size();
        const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
        stack<pair<int, int>> todo;
        todo.push({r0, c0});
        grid[r0][c0] = '0';                       
        while (!todo.empty()) {
            auto [r, c] = todo.top();
            todo.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] != '1') continue;
                grid[nr][nc] = '0';
                todo.push({nr, nc});
            }
        }
    }   

    int numIslands(vector<vector<char>>& grid) {

        int count = 0;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    sink(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 11_graphDFS_numberOfIslands.cpp && ./a.out
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

    // Grids are written as rows of text and converted to vector<vector<char>> below.
    struct Case { vector<string> rows; int expected; };
    vector<Case> cases = {
        {{"11110", "11010", "11000", "00000"}, 1},
        {{"11000", "11000", "00100", "00011"}, 3},
        {{"0"}, 0},
        {{"1"}, 1},
        {{"111", "101", "111"}, 1},
        {{"101", "010", "101"}, 5},
    };
    for (auto& c : cases) {
        vector<vector<char>> grid;
        for (auto& row : c.rows) grid.emplace_back(row.begin(), row.end());
        check(sol.numIslands(grid), c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
