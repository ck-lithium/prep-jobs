/*
 * Assign Cookies
 * LeetCode 455 (Easy) - https://leetcode.com/problems/assign-cookies/
 *
 * Each child i has a greed factor g[i]: the smallest cookie that makes them
 * happy. Each cookie j has a size s[j]. Cookie j makes child i happy if
 * s[j] >= g[i]. Every child gets at most one cookie.
 *
 * Return the largest number of children you can make happy.
 *
 * Example 1:
 *   Input:  g = [1, 2, 3], s = [1, 1]
 *   Output: 1
 *   Why:    both cookies have size 1, so only the child with greed 1 is happy.
 *
 * Example 2:
 *   Input:  g = [1, 2], s = [1, 2, 3]
 *   Output: 2
 *
 * Constraints:
 *   1 <= g.length <= 3 * 10^4
 *   0 <= s.length <= 3 * 10^4
 *   1 <= g[i], s[j] <= 2^31 - 1
 *
 * Target: O(n log n). Sort both, and give each cookie to the least greedy
 * child it can satisfy.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_assignCookies.cpp && ./a.out
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

    struct Case { vector<int> g, s; int expected; };
    vector<Case> cases = {
        {{1, 2, 3}, {1, 1}, 1},
        {{1, 2}, {1, 2, 3}, 2},
        {{1}, {}, 0},
        {{10, 9, 8, 7}, {5, 6, 7, 8}, 2},
        {{1, 1, 1}, {1, 1, 1}, 3},
        {{2, 3}, {1, 1, 1}, 0},
        {{1, 2, 3}, {3}, 1},
        {{3, 1, 2}, {2, 1}, 2},
    };
    for (auto& c : cases) check(sol.findContentChildren(c.g, c.s), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
