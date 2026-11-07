/*
 * 03 - SLIDING WINDOW: Longest Substring Without Repeating Characters
 * LeetCode 3 (Medium) - https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Given a string `s`, return the length of the longest substring in which no
 * character appears twice. A substring is a contiguous block of characters.
 *
 * Example 1:
 *   Input:  s = "abcabcbb"
 *   Output: 3
 *   Why:    "abc".
 *
 * Example 2:
 *   Input:  s = "bbbbb"
 *   Output: 1
 *   Why:    "b".
 *
 * Example 3:
 *   Input:  s = "pwwkew"
 *   Output: 3
 *   Why:    "wke". Note "pwke" doesn't count: it's a subsequence, not a substring.
 *
 * Constraints:
 *   0 <= s.length <= 5 * 10^4
 *   s contains English letters, digits, symbols and spaces.
 *
 * Target: O(n) time.
 *
 * How to spot this pattern: "longest / shortest contiguous subarray or substring
 * such that <condition>", where growing the window can only make the condition
 * worse and shrinking it can only make it better.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_slidingWindow_longestSubstringNoRepeats.cpp && ./a.out
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
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
        {"", 0},
        {" ", 1},
        {"abba", 2},
        {"dvdf", 3},
        {"tmmzuxt", 5},
    };
    for (auto& c : cases) check(sol.lengthOfLongestSubstring(c.s), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
