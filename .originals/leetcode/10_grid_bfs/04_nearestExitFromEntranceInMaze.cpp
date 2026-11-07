/*
 * Nearest Exit from Entrance in Maze
 * LeetCode 1926 (Medium) - https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 *
 * A maze is a grid of '.' (open) and '+' (wall) cells. You start at
 * entrance = [row, col], an open cell, and can step up, down, left or right
 * onto open cells, never off the grid.
 *
 * An exit is an open cell on the border of the grid. The entrance itself does
 * not count as an exit, even if it is on the border.
 *
 * Return the number of steps on the shortest path to the nearest exit, or -1
 * if no exit can be reached.
 *
 * Example 1:
 *   Input:  maze = ["++.+",
 *                   "...+",
 *                   "+++."], entrance = [1, 2]
 *   Output: 1
 *   Why:    one step up reaches the open border cell (0, 2).
 *
 * Example 2:
 *   Input:  maze = ["+++",
 *                   "...",
 *                   "+++"], entrance = [1, 0]
 *   Output: 2
 *   Why:    (1, 0) is on the border but is the entrance; (1, 2) is 2 steps away.
 *
 * Example 3:
 *   Input:  maze = [".+"], entrance = [0, 0]
 *   Output: -1
 *
 * Constraints:
 *   1 <= rows, cols <= 100
 *   Every cell is '.' or '+', and the entrance is a '.' cell.
 *
 * Target: O(rows * cols) with BFS.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_nearestExitFromEntranceInMaze.cpp && ./a.out
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

    // Mazes are written as rows of text and converted to vector<vector<char>>.
    struct Case { vector<string> rows; vector<int> entrance; int expected; };
    vector<Case> cases = {
        {{"++.+", "...+", "+++."}, {1, 2}, 1},
        {{"+++", "...", "+++"}, {1, 0}, 2},
        {{".+"}, {0, 0}, -1},
        {{"."}, {0, 0}, -1},
        {{"+++", "+.+", "+++"}, {1, 1}, -1},
        {{"...", "...", "..."}, {1, 1}, 1},
        {{".", ".", "."}, {0, 0}, 1},
        {{"+.+++", "+...+", "+++.+", "+...+", "+++++"}, {3, 1}, 7},   // winding path to (0, 1)
    };
    for (auto& c : cases) {
        vector<vector<char>> maze;
        for (auto& row : c.rows) maze.emplace_back(row.begin(), row.end());
        check(sol.nearestExit(maze, c.entrance), c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
