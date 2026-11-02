/*
 * Minimum Window Substring
 * LeetCode 76 (Hard) - https://leetcode.com/problems/minimum-window-substring/
 *
 * Given strings `s` and `t`, return the shortest substring of `s` that contains
 * every character of `t`, duplicates included (if t has two 'a's, the window
 * needs at least two 'a's). Return "" if there is no such substring.
 *
 * The tests are built so that the shortest window is unique.
 *
 * Example 1:
 *   Input:  s = "ADOBECODEBANC", t = "ABC"
 *   Output: "BANC"
 *
 * Example 2:
 *   Input:  s = "a", t = "a"
 *   Output: "a"
 *
 * Example 3:
 *   Input:  s = "a", t = "aa"
 *   Output: ""
 *   Why:    s has only one 'a'.
 *
 * Constraints:
 *   1 <= s.length, t.length <= 10^5
 *   s and t contain uppercase and lowercase English letters.
 *
 * Target: O(len(s) + len(t)) time. Grow the window until it contains all of
 * t, then shrink it from the left while it still does.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // TODO
        return "";
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_minimumWindowSubstring.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(const string& s) { return '"' + s + '"'; }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { string s, t, expected; };
    vector<Case> cases = {
        {"ADOBECODEBANC", "ABC", "BANC"},
        {"a", "a", "a"},
        {"a", "aa", ""},
        {"ab", "b", "b"},
        {"aa", "aa", "aa"},
        {"bba", "ab", "ba"},
        {"cabwefgewcwaefgcf", "cae", "cwae"},
        {"ADOBECODEBANC", "XYZ", ""},
        {"aAbB", "AB", "AbB"},
    };
    for (auto& c : cases) check(sol.minWindow(c.s, c.t), c.expected);

    // Big input: 99999 'a's and then a 'b'.
    string big(99999, 'a');
    big += 'b';
    check(sol.minWindow(big, "ab"), string("ab"));

    cout << passed << "/" << total << " tests passed\n";
}
