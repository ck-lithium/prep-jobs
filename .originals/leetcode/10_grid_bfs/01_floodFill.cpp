/*
 * Flood Fill
 * LeetCode 733 (Easy) - https://leetcode.com/problems/flood-fill/
 *
 * An image is a grid of pixel colours. Starting from pixel (sr, sc), repaint
 * it and every pixel connected to it with `color`. "Connected" means reachable
 * through up/down/left/right steps over pixels of the starting pixel's
 * original colour (diagonals don't count). Return the repainted image.
 *
 * This is the paint-bucket tool in an image editor.
 *
 * Example 1:
 *   Input:  image = [[1, 1, 1],
 *                    [1, 1, 0],
 *                    [1, 0, 1]], sr = 1, sc = 1, color = 2
 *   Output: [[2, 2, 2],
 *            [2, 2, 0],
 *            [2, 0, 1]]
 *   Why:    the bottom-right 1 only touches the rest diagonally.
 *
 * Example 2:
 *   Input:  image = [[0, 0, 0], [0, 0, 0]], sr = 0, sc = 0, color = 0
 *   Output: [[0, 0, 0], [0, 0, 0]]
 *
 * Constraints:
 *   1 <= rows, cols <= 50
 *   0 <= image[i][j], color < 2^16
 *   0 <= sr < rows, 0 <= sc < cols
 *
 * Target: O(rows * cols) with BFS (or DFS). Example 2 hides a trap: what does
 * your search do when the new colour equals the old one?
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_floodFill.cpp && ./a.out
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

    struct Case { vector<vector<int>> image; int sr, sc, color; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}, 1, 1, 2, {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}}},
        {{{0, 0, 0}, {0, 0, 0}}, 0, 0, 0, {{0, 0, 0}, {0, 0, 0}}},
        {{{0}}, 0, 0, 5, {{5}}},
        {{{1, 2}, {2, 1}}, 0, 0, 3, {{3, 2}, {2, 1}}},
        {{{1, 1}, {1, 1}}, 1, 1, 1, {{1, 1}, {1, 1}}},
        {{{0, 0, 0}, {0, 1, 1}}, 1, 1, 1, {{0, 0, 0}, {0, 1, 1}}},
        {{{3, 3, 3}, {3, 4, 3}, {3, 3, 3}}, 0, 0, 7, {{7, 7, 7}, {7, 4, 7}, {7, 7, 7}}},
    };
    for (auto& c : cases) check(sol.floodFill(c.image, c.sr, c.sc, c.color), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
