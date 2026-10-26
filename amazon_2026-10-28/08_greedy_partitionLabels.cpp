/*
 * 08 - GREEDY: Partition Labels
 * LeetCode 763 (Medium) - https://leetcode.com/problems/partition-labels/
 *
 * You are given a string `s`. Split it into as many parts as possible so that
 * each letter appears in at most one part. Gluing the parts back together in
 * order must give `s` again.
 *
 * Return a list with the length of each part, in order.
 *
 * Example 1:
 *   Input:  s = "ababcbacadefegdehijhklij"
 *   Output: [9, 7, 8]
 *   Why:    the parts are "ababcbaca", "defegde", "hijhklij".
 *           "ababcbacadefegde", "hijhklij" is also a valid split, but it has
 *           fewer parts.
 *
 * Example 2:
 *   Input:  s = "eccbbbbdec"
 *   Output: [10]
 *
 * Constraints:
 *   1 <= s.length <= 500
 *   s contains only lowercase English letters.
 *
 * Target: O(n) time.
 *
 * How to spot this pattern: you can make one local choice at a time and argue
 * that it never hurts the final answer. Often you precompute something first
 * (here: where each letter appears for the last time).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 08_greedy_partitionLabels.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
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

    struct Case { string s; vector<int> expected; };
    vector<Case> cases = {
        {"ababcbacadefegdehijhklij", {9, 7, 8}},
        {"eccbbbbdec", {10}},
        {"abc", {1, 1, 1}},
        {"a", {1}},
        {"caedbdedda", {1, 9}},
        {"abac", {3, 1}},
    };
    for (auto& c : cases) check(sol.partitionLabels(c.s), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
