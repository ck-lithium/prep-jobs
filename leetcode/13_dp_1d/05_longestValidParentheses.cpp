/*
 * Longest Valid Parentheses
 * LeetCode 32 (Hard) - https://leetcode.com/problems/longest-valid-parentheses/
 *
 * Given a string of '(' and ')', return the length of its longest substring
 * that is a valid (properly matched) set of parentheses.
 *
 * Example 1:
 *   Input:  s = "(()"
 *   Output: 2
 *   Why:    "()".
 *
 * Example 2:
 *   Input:  s = ")()())"
 *   Output: 4
 *   Why:    "()()".
 *
 * Example 3:
 *   Input:  s = ""
 *   Output: 0
 *
 * Constraints:
 *   0 <= s.length <= 3 * 10^4
 *   s[i] is '(' or ')'.
 *
 * Target: O(n). The DP version: longest[i] is the longest valid substring
 * ending at position i. It's 0 when s[i] is '('. When s[i] is ')', look at
 * the character just before the valid block that ends at i - 1. (A stack of
 * indices also gives O(n).)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_longestValidParentheses.cpp && ./a.out
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

    struct Case { string s; int expected; };
    vector<Case> cases = {
        {"(()", 2},
        {")()())", 4},
        {"", 0},
        {"()", 2},
        {"()(())", 6},
        {"(()())", 6},
        {"())((())", 4},
        {")(", 0},
        {"((((", 0},
        {"()(()", 2},
    };
    for (auto& c : cases) check(sol.longestValidParentheses(c.s), c.expected);

    // Big input: "()" repeated 15000 times, all valid.
    string big;
    for (int i = 0; i < 15000; i++) big += "()";
    check(sol.longestValidParentheses(big), 30000);

    cout << passed << "/" << total << " tests passed\n";
}
