/*
 * Longest Common Prefix
 * LeetCode 14 (Easy) - https://leetcode.com/problems/longest-common-prefix/
 *
 * Given an array of strings, return the longest prefix that all of them share,
 * or "" if they share none.
 *
 * Example 1:
 *   Input:  strs = ["flower", "flow", "flight"]
 *   Output: "fl"
 *
 * Example 2:
 *   Input:  strs = ["dog", "racecar", "car"]
 *   Output: ""
 *
 * Constraints:
 *   1 <= strs.length <= 200
 *   0 <= strs[i].length <= 200
 *   strs[i] contains only lowercase English letters.
 *
 * Target: O(total characters). Comparing column by column is enough here; the
 * trie view is: insert every word, then walk down from the root while there is
 * exactly one child and no word has ended yet.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // TODO
        return "";
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_longestCommonPrefix.cpp && ./a.out
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

    struct Case { vector<string> strs; string expected; };
    vector<Case> cases = {
        {{"flower", "flow", "flight"}, "fl"},
        {{"dog", "racecar", "car"}, ""},
        {{"a"}, "a"},
        {{"", ""}, ""},
        {{"ab", "a"}, "a"},
        {{"interspecies", "interstellar", "interstate"}, "inters"},
        {{"same", "same"}, "same"},
        {{"abc", "abd", "ab"}, "ab"},
    };
    for (auto& c : cases) check(sol.longestCommonPrefix(c.strs), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
