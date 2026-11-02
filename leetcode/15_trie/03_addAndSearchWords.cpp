/*
 * Design Add and Search Words Data Structure
 * LeetCode 211 (Medium) - https://leetcode.com/problems/design-add-and-search-words-data-structure/
 *
 * Implement the WordDictionary class:
 *   WordDictionary()            Creates an empty dictionary.
 *   void addWord(string word)   Adds `word`.
 *   bool search(string word)    True if some added word matches `word`, where
 *                               a '.' in `word` matches any single letter.
 *
 * Example:
 *   WordDictionary d;
 *   d.addWord("bad");
 *   d.addWord("dad");
 *   d.addWord("mad");
 *   d.search("pad");   // false
 *   d.search("bad");   // true
 *   d.search(".ad");   // true
 *   d.search("b..");   // true
 *
 * Constraints:
 *   1 <= word.length <= 25
 *   Added words contain only lowercase letters; searched words also contain
 *   at most 2 dots.
 *   At most 10^4 calls in total.
 *
 * Target: a trie. A letter follows one child; a '.' tries every child.
 */

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    WordDictionary() {
        // TODO
    }

    void addWord(string word) {
        // TODO
    }

    bool search(string word) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_addAndSearchWords.cpp && ./a.out
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
    WordDictionary d;
    d.addWord("bad");
    d.addWord("dad");
    d.addWord("mad");
    check(d.search("pad"), false);
    check(d.search("bad"), true);
    check(d.search(".ad"), true);
    check(d.search("b.."), true);
    check(d.search("..."), true);
    check(d.search("...."), false);   // no 4-letter words
    check(d.search("b.d"), true);
    check(d.search("."), false);      // no 1-letter words yet
    d.addWord("a");
    check(d.search("."), true);
    check(d.search("..d"), true);
    check(d.search("ba"), false);     // a prefix is not a word

    cout << passed << "/" << total << " tests passed\n";
}
