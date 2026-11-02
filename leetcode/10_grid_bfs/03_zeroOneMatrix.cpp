/*
 * 01 Matrix
 * LeetCode 542 (Medium) - https://leetcode.com/problems/01-matrix/
 *
 * Given a matrix of 0s and 1s, return a matrix of the same size where each
 * cell holds the distance to the nearest 0, counting up/down/left/right steps.
 *
 * Example 1:
 *   Input:  [[0, 0, 0],
 *            [0, 1, 0],
 *            [0, 0, 0]]
 *   Output: [[0, 0, 0],
 *            [0, 1, 0],
 *            [0, 0, 0]]
 *
 * Example 2:
 *   Input:  [[0, 0, 0],
 *            [0, 1, 0],
 *            [1, 1, 1]]
 *   Output: [[0, 0, 0],
 *            [0, 1, 0],
 *            [1, 2, 1]]
 *
 * Constraints:
 *   1 <= rows * cols <= 10^4
 *   Each cell is 0 or 1, and there is at least one 0.
 *
 * Target: O(rows * cols). Searching from every 1 separately is too slow; start
 * one BFS from all the 0s at once instead (like the rotting oranges in the
 * initial set).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_zeroOneMatrix.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }
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

    struct Case { vector<vector<int>> mat; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}},
        {{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}, {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}}},
        {{{0}}, {{0}}},
        {{{0, 1, 1, 1}}, {{0, 1, 2, 3}}},
        {{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, {{2, 1, 2}, {1, 0, 1}, {2, 1, 2}}},
        {{{1}, {1}, {0}}, {{2}, {1}, {0}}},
    };
    for (auto& c : cases) check(sol.updateMatrix(c.mat), c.expected);

    // Big input: 100 x 100 ones with a single 0 in the top-left corner, so cell
    // (i, j) is at distance i + j. (Prints true/false only.)
    vector<vector<int>> big(100, vector<int>(100, 1)), bigExpected(100, vector<int>(100));
    big[0][0] = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) bigExpected[i][j] = i + j;
    check(sol.updateMatrix(big) == bigExpected, true);

    cout << passed << "/" << total << " tests passed\n";
}
