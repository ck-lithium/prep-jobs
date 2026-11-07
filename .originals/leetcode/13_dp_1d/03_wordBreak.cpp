/*
 * Word Break
 * LeetCode 139 (Medium) - https://leetcode.com/problems/word-break/
 *
 * Given a string `s` and a list of words `wordDict`, return true if `s` can be
 * split into a sequence of one or more dictionary words. A word can be used
 * any number of times.
 *
 * Example 1:
 *   Input:  s = "leetcode", wordDict = ["leet", "code"]
 *   Output: true
 *
 * Example 2:
 *   Input:  s = "applepenapple", wordDict = ["apple", "pen"]
 *   Output: true
 *   Why:    "apple" + "pen" + "apple"; reusing "apple" is fine.
 *
 * Example 3:
 *   Input:  s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 *   Output: false
 *
 * Constraints:
 *   1 <= s.length <= 300
 *   1 <= wordDict.length <= 1000
 *   1 <= wordDict[i].length <= 20
 *   s and the words contain only lowercase English letters; the words are
 *   all different.
 *
 * Target: O(n * maxWordLength) checks. canBreak[i] = "the first i characters
 * can be split": it's true if some dictionary word ends at i and canBreak is
 * true where that word starts.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_wordBreak.cpp && ./a.out
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

    struct Case { string s; vector<string> wordDict; bool expected; };
    vector<Case> cases = {
        {"leetcode", {"leet", "code"}, true},
        {"applepenapple", {"apple", "pen"}, true},
        {"catsandog", {"cats", "dog", "sand", "and", "cat"}, false},
        {"a", {"a"}, true},
        {"ab", {"a"}, false},
        {"cars", {"car", "ca", "rs"}, true},
        {"aaaaaaa", {"aaaa", "aaa"}, true},
        {"goalspecial", {"go", "goal", "goals", "special"}, true},
    };
    for (auto& c : cases) check(sol.wordBreak(c.s, c.wordDict), c.expected);

    // Big input: 150 a's and then a b, with the words a, aa, ..., aaaaaaaaaa.
    // The b makes it impossible, and plain backtracking tries an astronomical
    // number of splits before it gives up.
    vector<string> words;
    for (int len = 1; len <= 10; len++) words.push_back(string(len, 'a'));
    check(sol.wordBreak(string(150, 'a') + "b", words), false);

    cout << passed << "/" << total << " tests passed\n";
}
