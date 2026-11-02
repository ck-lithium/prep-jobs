/*
 * 15 - TRIE: Search Suggestions System
 * LeetCode 1268 (Medium) - https://leetcode.com/problems/search-suggestions-system/
 *
 * You are given an array of different product names `products` and a string
 * `searchWord`. Picture a search box: after each character of `searchWord` is
 * typed, it shows at most three products that start with what has been typed so
 * far. If more than three products match, it shows the three that come first in
 * alphabetical (lexicographic) order.
 *
 * Return a list where element i holds the suggestions shown after typing the
 * first i + 1 characters of `searchWord`.
 *
 * Example 1:
 *   Input:  products = ["mobile", "mouse", "moneypot", "monitor", "mousepad"]
 *           searchWord = "mouse"
 *   Output: [["mobile", "moneypot", "monitor"],
 *            ["mobile", "moneypot", "monitor"],
 *            ["mouse", "mousepad"],
 *            ["mouse", "mousepad"],
 *            ["mouse", "mousepad"]]
 *   Why:    after "m" and "mo" all five products match, and the first three in
 *           alphabetical order are shown. From "mou" on only two products match.
 *
 * Example 2:
 *   Input:  products = ["havana"], searchWord = "tatiana"
 *   Output: [[], [], [], [], [], [], []]
 *
 * Constraints:
 *   1 <= products.length <= 1000
 *   1 <= products[i].length <= 3000
 *   1 <= sum of all products[i].length <= 2 * 10^4
 *   All products are different and contain only lowercase English letters.
 *   1 <= searchWord.length <= 1000
 *   searchWord contains only lowercase English letters.
 *
 * Target: build a trie of the products. (Sorting plus binary search also works,
 * and is worth trying second.)
 *
 * How to spot this pattern: many "starts with" / prefix questions over a fixed
 * set of words: autocomplete, search suggestions, word lookups.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 15_trie_searchSuggestions.cpp && ./a.out
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

    struct Case { vector<string> products; string searchWord; vector<vector<string>> expected; };
    vector<Case> cases = {
        {{"mobile", "mouse", "moneypot", "monitor", "mousepad"}, "mouse",
         {{"mobile", "moneypot", "monitor"},
          {"mobile", "moneypot", "monitor"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"},
          {"mouse", "mousepad"}}},
        {{"havana"}, "havana",
         {{"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}, {"havana"}}},
        {{"bags", "baggage", "banner", "box", "cloths"}, "bags",
         {{"baggage", "bags", "banner"},
          {"baggage", "bags", "banner"},
          {"baggage", "bags"},
          {"bags"}}},
        {{"havana"}, "tatiana",
         {{}, {}, {}, {}, {}, {}, {}}},
    };
    for (auto& c : cases) check(sol.suggestedProducts(c.products, c.searchWord), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
