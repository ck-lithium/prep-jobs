/*
 * Implement Trie (Prefix Tree)
 * LeetCode 208 (Medium) - https://leetcode.com/problems/implement-trie-prefix-tree/
 *
 * A trie stores strings as a tree of characters: each node has up to 26
 * children (one per letter), and a flag that says whether a word ends there.
 * Words that share a prefix share the nodes for it.
 *
 * Implement the Trie class:
 *   Trie()                          Creates an empty trie.
 *   void insert(string word)        Adds `word`.
 *   bool search(string word)        True if `word` was inserted.
 *   bool startsWith(string prefix)  True if some inserted word starts with
 *                                   `prefix`.
 *
 * Example:
 *   Trie trie;
 *   trie.insert("apple");
 *   trie.search("apple");     // true
 *   trie.search("app");       // false: "app" was never inserted
 *   trie.startsWith("app");   // true
 *   trie.insert("app");
 *   trie.search("app");       // true
 *
 * Constraints:
 *   1 <= word.length, prefix.length <= 2000
 *   Only lowercase English letters.
 *   At most 3 * 10^4 calls in total.
 *
 * Target: O(length of the word) per call.
 */

#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    Trie() {
        // TODO
    }

    void insert(string word) {
        // TODO
    }

    bool search(string word) {
        // TODO
        return false;
    }

    bool startsWith(string prefix) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_implementTrie.cpp && ./a.out
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
    // The example from the problem.
    {
        Trie trie;
        trie.insert("apple");
        check(trie.search("apple"), true);
        check(trie.search("app"), false);
        check(trie.startsWith("app"), true);
        trie.insert("app");
        check(trie.search("app"), true);
    }
    // An empty trie, then a single letter.
    {
        Trie trie;
        check(trie.search("a"), false);
        check(trie.startsWith("a"), false);
        trie.insert("a");
        check(trie.search("a"), true);
        check(trie.startsWith("a"), true);
        check(trie.search("aa"), false);
    }
    // Words sharing a prefix.
    {
        Trie trie;
        trie.insert("car");
        trie.insert("card");
        trie.insert("care");
        check(trie.search("ca"), false);
        check(trie.startsWith("ca"), true);
        check(trie.search("card"), true);
        check(trie.search("cards"), false);
        check(trie.startsWith("cards"), false);
        check(trie.startsWith("care"), true);
    }

    cout << passed << "/" << total << " tests passed\n";
}
