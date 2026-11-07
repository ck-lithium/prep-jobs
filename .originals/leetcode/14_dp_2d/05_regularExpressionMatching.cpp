/*
 * Regular Expression Matching
 * LeetCode 10 (Hard) - https://leetcode.com/problems/regular-expression-matching/
 *
 * Implement matching of a string `s` against a pattern `p` that supports:
 *   '.'  matches any single character;
 *   '*'  matches zero or more copies of the element just before it.
 *
 * The pattern must match the whole string, not just part of it.
 *
 * Example 1:
 *   Input:  s = "aa", p = "a"
 *   Output: false
 *   Why:    "a" matches only the first character.
 *
 * Example 2:
 *   Input:  s = "aa", p = "a*"
 *   Output: true
 *   Why:    "a*" is zero or more a's.
 *
 * Example 3:
 *   Input:  s = "ab", p = ".*"
 *   Output: true
 *   Why:    ".*" is zero or more of any character.
 *
 * Constraints:
 *   1 <= s.length, p.length <= 20
 *   s contains lowercase letters; p contains lowercase letters, '.' and '*'.
 *   Every '*' comes right after a letter or a '.'.
 *
 * Target: O(len(s) * len(p)). match[i][j] = "the first i characters of s match
 * the first j of p". The tricky case is a '*': it either matches nothing (skip
 * the "x*" pair) or eats one more character of s.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_regularExpressionMatching.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { string s, p; bool expected; };
    vector<Case> cases = {
        {"aa", "a", false},
        {"aa", "a*", true},
        {"ab", ".*", true},
        {"aab", "c*a*b", true},
        {"mississippi", "mis*is*p*.", false},
        {"mississippi", "mis*is*ip*.", true},
        {"a", "ab*", true},
        {"ab", ".*c", false},
        {"aaa", "a*a", true},
        {"aaa", "ab*a*c*a", true},
        {"a", ".*..a*", false},
    };
    for (auto& c : cases) check(sol.isMatch(c.s, c.p), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
