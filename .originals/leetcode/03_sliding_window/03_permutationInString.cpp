/*
 * Permutation in String
 * LeetCode 567 (Medium) - https://leetcode.com/problems/permutation-in-string/
 *
 * Given two strings `s1` and `s2`, return true if `s2` contains some
 * rearrangement (permutation) of `s1` as a contiguous substring.
 *
 * Example 1:
 *   Input:  s1 = "ab", s2 = "eidbaooo"
 *   Output: true
 *   Why:    s2 contains "ba".
 *
 * Example 2:
 *   Input:  s1 = "ab", s2 = "eidboaoo"
 *   Output: false
 *
 * Constraints:
 *   1 <= s1.length, s2.length <= 10^4
 *   s1 and s2 contain only lowercase English letters.
 *
 * Target: O(len(s2)) time with a fixed-size window and letter counts.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_permutationInString.cpp && ./a.out
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

    struct Case { string s1, s2; bool expected; };
    vector<Case> cases = {
        {"ab", "eidbaooo", true},
        {"ab", "eidboaoo", false},
        {"adc", "dcda", true},
        {"a", "a", true},
        {"abc", "ab", false},
        {"hello", "ooolleoooleh", false},
        {"abc", "bbbca", true},
        {"aab", "abaa", true},
        {"xyz", "xxyyzz", false},
    };
    for (auto& c : cases) check(sol.checkInclusion(c.s1, c.s2), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
