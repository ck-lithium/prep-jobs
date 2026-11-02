/*
 * 14 - DYNAMIC PROGRAMMING (2D): Longest Common Subsequence
 * LeetCode 1143 (Medium) - https://leetcode.com/problems/longest-common-subsequence/
 *
 * Given two strings `text1` and `text2`, return the length of their longest
 * common subsequence. If they have none, return 0.
 *
 * A subsequence is what you get by deleting zero or more characters from a
 * string without changing the order of the rest. For example, "ace" is a
 * subsequence of "abcde", but "aec" is not. A common subsequence is one that is
 * a subsequence of both strings.
 *
 * Example 1:
 *   Input:  text1 = "abcde", text2 = "ace"
 *   Output: 3
 *   Why:    "ace".
 *
 * Example 2:
 *   Input:  text1 = "abc", text2 = "abc"
 *   Output: 3
 *
 * Example 3:
 *   Input:  text1 = "abc", text2 = "def"
 *   Output: 0
 *
 * Constraints:
 *   1 <= text1.length, text2.length <= 1000
 *   Both strings contain only lowercase English letters.
 *
 * Target: O(n * m) time. Follow-up: O(min(n, m)) extra space.
 *
 * How to spot this pattern: two strings or arrays compared position by position
 * (common subsequence, edit distance), or counting / optimising paths in a grid.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 14_dp2D_longestCommonSubsequence.cpp && ./a.out
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

    struct Case { string text1, text2; int expected; };
    vector<Case> cases = {
        {"abcde", "ace", 3},
        {"abc", "abc", 3},
        {"abc", "def", 0},
        {"a", "a", 1},
        {"ezupkr", "ubmrapg", 2},
        {"bsbininm", "jmjkbkjkv", 1},
        {"oxcpqrsvwf", "shmtulqrypy", 2},
    };
    for (auto& c : cases) check(sol.longestCommonSubsequence(c.text1, c.text2), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
