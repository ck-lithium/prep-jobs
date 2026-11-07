/*
 * Pascal's Triangle
 * LeetCode 118 (Easy) - https://leetcode.com/problems/pascals-triangle/
 *
 * Return the first `numRows` rows of Pascal's triangle. Each row starts and
 * ends with 1, and every other number is the sum of the two numbers directly
 * above it:
 *
 *           1
 *          1 1
 *         1 2 1
 *        1 3 3 1
 *       1 4 6 4 1
 *
 * Example 1:
 *   Input:  numRows = 5
 *   Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
 *
 * Example 2:
 *   Input:  numRows = 1
 *   Output: [[1]]
 *
 * Constraints:
 *   1 <= numRows <= 30
 *
 * Target: O(numRows^2). The simplest 2-D table: each row is built from the
 * one before it.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_pascalsTriangle.cpp && ./a.out
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

    struct Case { int numRows; vector<vector<int>> expected; };
    vector<Case> cases = {
        {5, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}},
        {1, {{1}}},
        {2, {{1}, {1, 1}}},
        {3, {{1}, {1, 1}, {1, 2, 1}}},
    };
    for (auto& c : cases) check(sol.generate(c.numRows), c.expected);

    // 30 rows: check the row count, the last row's middle (29 choose 14) and
    // the last row's sum (2^29).
    auto rows = sol.generate(30);
    check((int)rows.size(), 30);
    check(rows.empty() || rows.back().size() < 15 ? -1 : rows.back()[14], 77558760);
    long long sum = 0;
    if (!rows.empty()) for (int x : rows.back()) sum += x;
    check((int)sum, 536870912);

    cout << passed << "/" << total << " tests passed\n";
}
