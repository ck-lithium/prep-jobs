/*
 * Number of Submatrices That Sum to Target
 * LeetCode 1074 (Hard) - https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
 *
 * Given a matrix and an integer `target`, return how many non-empty
 * submatrices have a sum equal to `target`.
 *
 * A submatrix is any rectangle of cells (x1..x2, y1..y2) with x1 <= x2 and
 * y1 <= y2. Two submatrices are different if any of their corners differ.
 *
 * Example 1:
 *   Input:  matrix = [[0, 1, 0],
 *                     [1, 1, 1],
 *                     [0, 1, 0]], target = 0
 *   Output: 4
 *   Why:    the four 1 x 1 corners are 0.
 *
 * Example 2:
 *   Input:  matrix = [[1, -1],
 *                     [-1, 1]], target = 0
 *   Output: 5
 *   Why:    two 1 x 2 rows, two 2 x 1 columns and the whole 2 x 2 matrix.
 *
 * Example 3:
 *   Input:  matrix = [[904]], target = 0
 *   Output: 0
 *
 * Constraints:
 *   1 <= rows, cols <= 100
 *   -1000 <= matrix[i][j] <= 1000
 *   -10^8 <= target <= 10^8
 *
 * Target: O(rows^2 * cols). Fix a top and a bottom row; the column sums between
 * them form a 1-D array, and the question becomes "Subarray Sum Equals K"
 * (problem 04 of the initial set).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_numberOfSubmatricesThatSumToTarget.cpp && ./a.out
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

    struct Case { vector<vector<int>> matrix; int target; int expected; };
    vector<Case> cases = {
        {{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}}, 0, 4},
        {{{1, -1}, {-1, 1}}, 0, 5},
        {{{904}}, 0, 0},
        {{{1}}, 1, 1},
        {{{0, 0}, {0, 0}}, 0, 9},
        {{{1, 2}, {3, 4}}, 3, 2},
        {{{1, 2, 3}}, 3, 2},
        {{{1}, {2}, {3}}, 3, 2},
    };
    for (auto& c : cases) check(sol.numSubmatrixSumTarget(c.matrix, c.target), c.expected);

    // Big input: a 100 x 100 matrix of zeros, target 0. Every submatrix counts:
    // (100 * 101 / 2)^2 = 25502500.
    vector<vector<int>> big(100, vector<int>(100, 0));
    check(sol.numSubmatrixSumTarget(big, 0), 25502500);

    cout << passed << "/" << total << " tests passed\n";
}
