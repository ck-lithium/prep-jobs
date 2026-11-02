/*
 * Climbing Stairs
 * LeetCode 70 (Easy) - https://leetcode.com/problems/climbing-stairs/
 *
 * A staircase has `n` steps. Each move, you climb either 1 or 2 steps. In how
 * many different ways can you reach the top?
 *
 * Example 1:
 *   Input:  n = 2
 *   Output: 2
 *   Why:    1 + 1, or 2.
 *
 * Example 2:
 *   Input:  n = 3
 *   Output: 3
 *   Why:    1 + 1 + 1, 1 + 2, or 2 + 1.
 *
 * Constraints:
 *   1 <= n <= 45
 *
 * Target: O(n) time, O(1) space. The last move was either 1 step (from n - 1)
 * or 2 steps (from n - 2), so ways(n) = ways(n - 1) + ways(n - 2). Plain
 * recursion on that formula repeats the same work exponentially often.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_climbingStairs.cpp && ./a.out
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

    struct Case { int n; int expected; };
    vector<Case> cases = {
        {2, 2},
        {3, 3},
        {1, 1},
        {4, 5},
        {5, 8},
        {10, 89},
        {45, 1836311903},   // plain recursion makes about 3.7 billion calls here
    };
    for (auto& c : cases) check(sol.climbStairs(c.n), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
