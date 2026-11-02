/*
 * Number of Provinces
 * LeetCode 547 (Medium) - https://leetcode.com/problems/number-of-provinces/
 *
 * There are n cities. isConnected[i][j] is 1 if cities i and j are directly
 * connected, and 0 otherwise. Cities connected directly or through other
 * cities form a "province". Return the number of provinces.
 *
 * Example 1:
 *   Input:  isConnected = [[1, 1, 0],
 *                          [1, 1, 0],
 *                          [0, 0, 1]]
 *   Output: 2
 *   Why:    cities 0 and 1 form one province, city 2 another.
 *
 * Example 2:
 *   Input:  isConnected = [[1, 0, 0],
 *                          [0, 1, 0],
 *                          [0, 0, 1]]
 *   Output: 3
 *
 * Constraints:
 *   1 <= n <= 200
 *   isConnected[i][i] == 1, and isConnected[i][j] == isConnected[j][i].
 *
 * Target: O(n^2). Count connected components: start a DFS from every city
 * that hasn't been visited yet. Note the input is an adjacency matrix, not an
 * edge list. (Union-find is the other classic way.)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_numberOfProvinces.cpp && ./a.out
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

    struct Case { vector<vector<int>> isConnected; int expected; };
    vector<Case> cases = {
        {{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, 2},
        {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3},
        {{{1}}, 1},
        {{{1, 1}, {1, 1}}, 1},
        {{{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}}, 1},   // 0-3, 3-2, 2-1
        {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}, 4},
        {{{1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}}, 2},
    };
    for (auto& c : cases) check(sol.findCircleNum(c.isConnected), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
