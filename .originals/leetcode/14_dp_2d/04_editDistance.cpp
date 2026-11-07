/*
 * Edit Distance
 * LeetCode 72 (Medium) - https://leetcode.com/problems/edit-distance/
 *
 * Given two strings `word1` and `word2`, return the minimum number of
 * operations needed to turn word1 into word2. Each operation is one of:
 *   - insert a character,
 *   - delete a character,
 *   - replace a character with another.
 *
 * Example 1:
 *   Input:  word1 = "horse", word2 = "ros"
 *   Output: 3
 *   Why:    horse -> rorse (replace h with r) -> rose (delete r) -> ros (delete e).
 *
 * Example 2:
 *   Input:  word1 = "intention", word2 = "execution"
 *   Output: 5
 *
 * Constraints:
 *   0 <= word1.length, word2.length <= 500
 *   Both contain only lowercase English letters.
 *
 * Target: O(n * m) time; follow-up O(min(n, m)) space. dist[i][j] = edits to
 * turn the first i characters of word1 into the first j of word2. It's the
 * same shape as Longest Common Subsequence (problem 14 of the initial set).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_editDistance.cpp && ./a.out
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

    struct Case { string word1, word2; int expected; };
    vector<Case> cases = {
        {"horse", "ros", 3},
        {"intention", "execution", 5},
        {"", "", 0},
        {"a", "", 1},
        {"", "abc", 3},
        {"abc", "abc", 0},
        {"kitten", "sitting", 3},
        {"sunday", "saturday", 3},
        {"flaw", "lawn", 2},
    };
    for (auto& c : cases) check(sol.minDistance(c.word1, c.word2), c.expected);

    // Big input: 500 a's against 500 b's: replace every character.
    check(sol.minDistance(string(500, 'a'), string(500, 'b')), 500);

    cout << passed << "/" << total << " tests passed\n";
}
