/*
 * Pacific Atlantic Water Flow
 * LeetCode 417 (Medium) - https://leetcode.com/problems/pacific-atlantic-water-flow/
 *
 * An island is a grid of cells, and heights[r][c] is the height of each cell.
 * The Pacific Ocean touches the top and left edges of the grid; the Atlantic
 * touches the bottom and right edges.
 *
 * Rain water flows from a cell to a neighbour (up, down, left or right) whose
 * height is less than or equal to the cell's own. Water on a cell next to an
 * ocean can flow into that ocean.
 *
 * Return the coordinates [r, c] of every cell from which water can reach
 * both oceans, in any order.
 *
 * Example 1:
 *   Input:  heights = [[1, 2, 2, 3, 5],
 *                      [3, 2, 3, 4, 4],
 *                      [2, 4, 5, 3, 1],
 *                      [6, 7, 1, 4, 5],
 *                      [5, 1, 1, 2, 4]]
 *   Output: [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
 *
 * Example 2:
 *   Input:  heights = [[1]]
 *   Output: [[0, 0]]
 *
 * Constraints:
 *   1 <= rows, cols <= 200
 *   0 <= heights[r][c] <= 10^5
 *
 * Target: O(rows * cols). Searching downhill from every cell is too slow.
 * Turn it around: search uphill from each ocean's edge cells, and return the
 * cells both searches reach.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_pacificAtlanticWaterFlow.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
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

    struct Case { vector<vector<int>> heights; vector<vector<int>> expected; };  // expected is sorted
    vector<Case> cases = {
        {{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}},
         {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}}},
        {{{1}}, {{0, 0}}},
        {{{2, 1}, {1, 2}}, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}},
        {{{10, 10, 10}, {10, 1, 10}, {10, 10, 10}},
         {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}},   // the pit can't drain
        {{{1, 2, 3}}, {{0, 0}, {0, 1}, {0, 2}}},   // one row touches both oceans everywhere
    };
    for (auto& c : cases) {
        // Any order is accepted, so sort the answer before comparing.
        auto got = sol.pacificAtlantic(c.heights);
        sort(got.begin(), got.end());
        check(got, c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
