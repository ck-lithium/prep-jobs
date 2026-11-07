/*
 * Group Anagrams
 * LeetCode 49 (Medium) - https://leetcode.com/problems/group-anagrams/
 *
 * Given an array of strings `strs`, group together the strings that are
 * anagrams of each other (same letters, same counts, any order). Return the
 * groups in any order, with the strings inside each group in any order.
 *
 * Example 1:
 *   Input:  strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 *   Output: [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
 *
 * Example 2:
 *   Input:  strs = [""]
 *   Output: [[""]]
 *
 * Example 3:
 *   Input:  strs = ["a"]
 *   Output: [["a"]]
 *
 * Constraints:
 *   1 <= strs.length <= 10^4
 *   0 <= strs[i].length <= 100
 *   strs[i] contains only lowercase English letters.
 *
 * Target: O(n * k log k) time with sorting, or O(n * k) with letter counts,
 * where k is the length of the longest string.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_groupAnagrams.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(const string& s) { return '"' + s + '"'; }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

// Any order is accepted, so sort inside each group and then sort the groups.
vector<vector<string>> normalize(vector<vector<string>> groups) {
    for (auto& g : groups) sort(g.begin(), g.end());
    sort(groups.begin(), groups.end());
    return groups;
}

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { vector<string> strs; vector<vector<string>> expected; };
    vector<Case> cases = {
        {{"eat", "tea", "tan", "ate", "nat", "bat"}, {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}},
        {{""}, {{""}}},
        {{"a"}, {{"a"}}},
        {{"abc", "bca", "cab", "xyz", "zyx", "q"}, {{"abc", "bca", "cab"}, {"xyz", "zyx"}, {"q"}}},
        {{"a", "a", "b"}, {{"a", "a"}, {"b"}}},
        {{"", "", ""}, {{"", "", ""}}},
        {{"ab", "ba", "abb", "bab", "bba", "aab"}, {{"ab", "ba"}, {"abb", "bab", "bba"}, {"aab"}}},
    };
    for (auto& c : cases) check(normalize(sol.groupAnagrams(c.strs)), normalize(c.expected));

    cout << passed << "/" << total << " tests passed\n";
}
