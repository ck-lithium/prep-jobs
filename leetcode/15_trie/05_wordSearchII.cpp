/*
 * Word Search II
 * LeetCode 212 (Hard) - https://leetcode.com/problems/word-search-ii/
 *
 * Given a grid of letters and a list of words, return every word that can be
 * spelled by a path through the grid. A path moves up, down, left or right
 * between neighbouring cells, and can't use the same cell twice within one
 * word. Return the words in any order.
 *
 * Example 1:
 *   Input:  board = [o a a n
 *                    e t a e
 *                    i h k r
 *                    i f l v], words = ["oath", "pea", "eat", "rain"]
 *   Output: ["eat", "oath"]
 *
 * Example 2:
 *   Input:  board = [a b
 *                    c d], words = ["abcb"]
 *   Output: []
 *   Why:    spelling it would need the b cell twice.
 *
 * Constraints:
 *   1 <= rows, cols <= 12
 *   1 <= words.length <= 3 * 10^4
 *   1 <= words[i].length <= 10
 *   Only lowercase letters; all words are different.
 *
 * Target: put all the words in a trie and run one DFS per starting cell,
 * following the trie as you go. Searching for each word separately repeats
 * the same work for every shared prefix.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_wordSearchII.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(const string& s) { return '"' + s + '"'; }
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

    // Boards are written as rows of text; expected answers are sorted.
    struct Case { vector<string> rows; vector<string> words; vector<string> expected; };
    vector<Case> cases = {
        {{"oaan", "etae", "ihkr", "iflv"}, {"oath", "pea", "eat", "rain"}, {"eat", "oath"}},
        {{"ab", "cd"}, {"abcb"}, {}},
        {{"a"}, {"a", "b"}, {"a"}},
        {{"ab", "cd"}, {"ab", "ac", "ad", "abdc", "acdb", "abc"}, {"ab", "abdc", "ac", "acdb"}},
        {{"aa"}, {"aaa"}, {}},
        {{"aa"}, {"aa"}, {"aa"}},
    };
    for (auto& c : cases) {
        vector<vector<char>> board;
        for (auto& row : c.rows) board.emplace_back(row.begin(), row.end());
        // Any order is accepted, so sort the answer before comparing.
        auto got = sol.findWords(board, c.words);
        sort(got.begin(), got.end());
        check(got, c.expected);
    }

    // Big input: a 12 x 12 board of a's. The words are a, aa, ..., aaaaaaaaaa
    // (all found) and nine a's followed by each other letter (none found).
    vector<vector<char>> big(12, vector<char>(12, 'a'));
    vector<string> words, expected;
    for (int len = 1; len <= 10; len++) words.push_back(string(len, 'a')), expected.push_back(string(len, 'a'));
    for (char c = 'b'; c <= 'z'; c++) words.push_back(string(9, 'a') + c);
    auto got = sol.findWords(big, words);
    sort(got.begin(), got.end());
    check(got, expected);

    cout << passed << "/" << total << " tests passed\n";
}
