/*
 * Valid Anagram
 * LeetCode 242 (Easy) - https://leetcode.com/problems/valid-anagram/
 *
 * Given two strings `s` and `t`, return true if `t` is an anagram of `s`: it
 * uses exactly the same letters, each the same number of times, in any order.
 *
 * Example 1:
 *   Input:  s = "anagram", t = "nagaram"
 *   Output: true
 *
 * Example 2:
 *   Input:  s = "rat", t = "car"
 *   Output: false
 *
 * Constraints:
 *   1 <= s.length, t.length <= 5 * 10^4
 *   s and t contain only lowercase English letters.
 *
 * Target: O(n) time.
 * Follow-up: what would you change if the strings could contain any Unicode
 * character?
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_validAnagram.cpp && ./a.out
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

    struct Case { string s, t; bool expected; };
    vector<Case> cases = {
        {"anagram", "nagaram", true},
        {"rat", "car", false},
        {"listen", "silent", true},
        {"a", "a", true},
        {"a", "ab", false},
        {"ab", "a", false},
        {"aacc", "ccac", false},
        {"abcdefghijklmnopqrstuvwxyz", "zyxwvutsrqponmlkjihgfedcba", true},
    };
    for (auto& c : cases) check(sol.isAnagram(c.s, c.t), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
