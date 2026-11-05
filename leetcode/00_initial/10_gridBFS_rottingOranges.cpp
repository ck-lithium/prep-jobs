/*
 * 10 - GRID BFS: Rotting Oranges
 * LeetCode 994 (Medium) - https://leetcode.com/problems/rotting-oranges/
 *
 * You are given an m x n grid where each cell is one of:
 *   0 - empty
 *   1 - a fresh orange
 *   2 - a rotten orange
 *
 * Every minute, each fresh orange directly next to a rotten one (up, down, left
 * or right, not diagonally) becomes rotten.
 *
 * Return the minimum number of minutes until no fresh orange is left. If that
 * can never happen, return -1.
 *
 * Example 1:
 *   Input:  grid = [[2, 1, 1],
 *                   [1, 1, 0],
 *                   [0, 1, 1]]
 *   Output: 4
 *
 * Example 2:
 *   Input:  grid = [[2, 1, 1],
 *                   [0, 1, 1],
 *                   [1, 0, 1]]
 *   Output: -1
 *   Why:    the orange in the bottom-left corner has no neighbour that can rot it.
 *
 * Example 3:
 *   Input:  grid = [[0, 2]]
 *   Output: 0
 *   Why:    there are no fresh oranges to begin with.
 *
 * Constraints:
 *   1 <= m, n <= 10
 *   grid[i][j] is 0, 1 or 2.
 *
 * Target: O(m * n) time.
 *
 * How to spot this pattern: "minimum steps / minutes / moves" in a grid or any
 * graph where every step costs the same. Something spreading from several
 * starting points at once is a strong hint.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int round = 0;
        queue<pair<int,int>> rotten;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    rotten.push({i,j});
                }
            }
        }

        int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

        while (!rotten.empty()) {

            int count = rotten.size();
                             
            for (int i = 0; i < count; i++) {
                auto [r, c] = rotten.front();
                rotten.pop();
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k], nc = c + dc[k];
                    if (nr < 0 || nc < 0 || nr > grid.size() - 1 || nc > grid[0].size() - 1 || grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                    
                    grid[nr][nc] = 2;
                    rotten.push({nr,nc});
                }
            }
            
            if (!rotten.empty()) round++;

        }

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return round;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 10_gridBFS_rottingOranges.cpp && ./a.out
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
        {{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4},
        {{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1},
        {{{0, 2}}, 0},
        {{{0}}, 0},
        {{{1}}, -1},
        {{{2, 2}, {1, 1}, {0, 0}, {2, 0}}, 1},
        {{{2, 1, 1}, {1, 1, 1}, {0, 1, 2}}, 2},
    };
    for (auto& c : cases) check(sol.orangesRotting(c.grid), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
