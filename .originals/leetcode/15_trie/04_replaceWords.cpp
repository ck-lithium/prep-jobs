/*
 * Replace Words
 * LeetCode 648 (Medium) - https://leetcode.com/problems/replace-words/
 *
 * You are given a dictionary of "roots" and a sentence of words separated by
 * single spaces. Replace every word that starts with a root by that root. If
 * several roots fit, use the shortest one. Return the new sentence.
 *
 * Example 1:
 *   Input:  dictionary = ["cat", "bat", "rat"],
 *           sentence = "the cattle was rattled by the battery"
 *   Output: "the cat was rat by the bat"
 *
 * Example 2:
 *   Input:  dictionary = ["a", "b", "c"],
 *           sentence = "aadsfasf absbs bbab cadsfafs"
 *   Output: "a a b c"
 *
 * Constraints:
 *   1 <= dictionary.length <= 1000
 *   1 <= dictionary[i].length <= 100
 *   1 <= sentence.length <= 10^6
 *   Only lowercase letters and single spaces, with no space at the start or end.
 *
 * Target: put the roots in a trie; for each word, walk the trie and stop at
 * the first node where a root ends.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // TODO
        return "";
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_replaceWords.cpp && ./a.out
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

    struct Case { vector<string> dictionary; string sentence, expected; };
    vector<Case> cases = {
        {{"cat", "bat", "rat"}, "the cattle was rattled by the battery", "the cat was rat by the bat"},
        {{"a", "b", "c"}, "aadsfasf absbs bbab cadsfafs", "a a b c"},
        {{"a", "aa", "aaa"}, "aaaa aa a", "a a a"},
        {{"catt", "cat", "bat", "rat"}, "the cattle was rattled by the battery", "the cat was rat by the bat"},
        {{"xyz"}, "hello world", "hello world"},
        {{"ab"}, "a ab abc", "a ab ab"},
    };
    for (auto& c : cases) check(sol.replaceWords(c.dictionary, c.sentence), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
