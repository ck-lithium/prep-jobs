/*
 * Best Time to Buy and Sell Stock
 * LeetCode 121 (Easy) - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 *
 * prices[i] is the price of a stock on day i. You may buy one share on one day
 * and sell it on a later day. Return the largest profit you can make, or 0 if
 * no trade makes a profit.
 *
 * Example 1:
 *   Input:  prices = [7, 1, 5, 3, 6, 4]
 *   Output: 5
 *   Why:    buy on day 1 (price 1) and sell on day 4 (price 6).
 *
 * Example 2:
 *   Input:  prices = [7, 6, 4, 3, 1]
 *   Output: 0
 *   Why:    the price only goes down, so the best is not to trade.
 *
 * Constraints:
 *   1 <= prices.length <= 10^5
 *   0 <= prices[i] <= 10^4
 *
 * Target: O(n) time, one pass.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_bestTimeToBuyAndSellStock.cpp && ./a.out
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

    struct Case { vector<int> prices; int expected; };
    vector<Case> cases = {
        {{7, 1, 5, 3, 6, 4}, 5},
        {{7, 6, 4, 3, 1}, 0},
        {{1}, 0},
        {{1, 2}, 1},
        {{2, 4, 1}, 2},
        {{3, 2, 6, 5, 0, 3}, 4},
        {{2, 1, 2, 1, 0, 1, 2}, 2},
    };
    for (auto& c : cases) check(sol.maxProfit(c.prices), c.expected);

    // Big input: 100000 days. The price falls from 10000 to 1, drops to 0, then
    // rises to 9999. An O(n^2) solution takes several seconds here.
    vector<int> big(100000);
    for (int i = 0; i < 50000; i++) big[i] = 10000 - i / 5;
    for (int i = 50000; i < 100000; i++) big[i] = (i - 50000) / 5;
    check(sol.maxProfit(big), 9999);

    cout << passed << "/" << total << " tests passed\n";
}
