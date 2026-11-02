/*
 * Online Stock Span
 * LeetCode 901 (Medium) - https://leetcode.com/problems/online-stock-span/
 *
 * Prices of a stock arrive one day at a time. The "span" of today's price is
 * the number of consecutive days, counting back from today and including
 * today, on which the price was less than or equal to today's price.
 *
 * Implement the StockSpanner class:
 *   StockSpanner()        Creates the object.
 *   int next(int price)   Records today's price and returns today's span.
 *
 * Example:
 *   prices arriving: 100, 80, 60, 70, 60, 75, 85
 *   spans returned:    1,  1,  1,  2,  1,  4,  6
 *   Why:  on the day of 75, the last 4 prices (60, 70, 60, 75) are <= 75.
 *
 * Constraints:
 *   1 <= price <= 10^5
 *   At most 10^4 calls to next.
 *
 * Target: O(1) amortised per call. Keep a stack of (price, span) pairs: when
 * today's price is at least the top's price, today's span swallows the top's.
 */

#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        // TODO
    }

    int next(int price) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_onlineStockSpan.cpp && ./a.out
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
    // Each case feeds the prices to a new StockSpanner and checks every span.
    struct Case { vector<int> prices; vector<int> expected; };
    vector<Case> cases = {
        {{100, 80, 60, 70, 60, 75, 85}, {1, 1, 1, 2, 1, 4, 6}},
        {{1, 2, 3, 4}, {1, 2, 3, 4}},
        {{5, 5, 5}, {1, 2, 3}},
        {{9, 8, 7}, {1, 1, 1}},
        {{28, 14, 28, 35, 46, 53, 66, 80, 87, 88}, {1, 1, 3, 4, 5, 6, 7, 8, 9, 10}},
        {{7, 2, 1, 2}, {1, 1, 1, 3}},
    };
    for (auto& c : cases) {
        StockSpanner spanner;
        vector<int> got;
        for (int p : c.prices) got.push_back(spanner.next(p));
        check(got, c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
