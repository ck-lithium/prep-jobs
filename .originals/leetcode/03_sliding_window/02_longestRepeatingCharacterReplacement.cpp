/*
 * Longest Repeating Character Replacement
 * LeetCode 424 (Medium) - https://leetcode.com/problems/longest-repeating-character-replacement/
 *
 * You are given a string `s` of uppercase English letters and an integer `k`.
 * You may change at most `k` characters of `s` into any other uppercase letter.
 *
 * Return the length of the longest substring that can be made of one repeated
 * letter after those changes.
 *
 * Example 1:
 *   Input:  s = "ABAB", k = 2
 *   Output: 4
 *   Why:    change both A's into B's (or both B's into A's).
 *
 * Example 2:
 *   Input:  s = "AABABBA", k = 1
 *   Output: 4
 *   Why:    turn the A at position 3 into a B, and positions 2-5 read "BBBB".
 *
 * Constraints:
 *   1 <= s.length <= 10^5
 *   s contains only uppercase English letters.
 *   0 <= k <= s.length
 *
 * Target: O(n) time. Hint: a window is fine as long as
 * (window length) - (count of its most frequent letter) <= k.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_longestRepeatingCharacterReplacement.cpp && ./a.out
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

    struct Case { string s; int k; int expected; };
    vector<Case> cases = {
        {"ABAB", 2, 4},
        {"AABABBA", 1, 4},
        {"A", 0, 1},
        {"AAAA", 0, 4},
        {"ABCDE", 1, 2},
        {"ABBB", 2, 4},
        {"AAABBC", 0, 3},
        {"BAAAB", 2, 5},
        {"ABCABCABC", 2, 4},
    };
    for (auto& c : cases) check(sol.characterReplacement(c.s, c.k), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
