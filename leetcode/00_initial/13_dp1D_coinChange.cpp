/*
 * 13 - DYNAMIC PROGRAMMING (1D): Coin Change
 * LeetCode 322 (Medium) - https://leetcode.com/problems/coin-change/
 *
 * You are given an array `coins` of different coin values and a target
 * `amount`. Return the fewest coins needed to make exactly `amount`. You can use
 * each coin value as many times as you want. If no combination of coins adds up
 * to `amount`, return -1.
 *
 * Example 1:
 *   Input:  coins = [1, 2, 5], amount = 11
 *   Output: 3
 *   Why:    5 + 5 + 1.
 *
 * Example 2:
 *   Input:  coins = [2], amount = 3
 *   Output: -1
 *
 * Example 3:
 *   Input:  coins = [1], amount = 0
 *   Output: 0
 *
 * Example 4:
 *   Input:  coins = [1, 3, 4], amount = 6
 *   Output: 2
 *   Why:    3 + 3. Always taking the biggest coin gives 4 + 1 + 1, which is worse.
 *
 * Constraints:
 *   1 <= coins.length <= 12
 *   1 <= coins[i] <= 2^31 - 1
 *   0 <= amount <= 10^4
 *
 * Target: O(amount * coins.length) time, O(amount) extra space.
 *
 * How to spot this pattern: "minimum / maximum / number of ways" to reach a
 * target, where a greedy choice can be wrong and the same sub-question (here:
 * "best way to make amount x") comes up again and again.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 13_dp1D_coinChange.cpp && ./a.out
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

    struct Case { vector<int> coins; int amount; int expected; };
    vector<Case> cases = {
        {{1, 2, 5}, 11, 3},
        {{2}, 3, -1},
        {{1}, 0, 0},
        {{1, 3, 4}, 6, 2},
        {{2, 5, 10, 1}, 27, 4},
        {{186, 419, 83, 408}, 6249, 20},
        {{2147483647}, 2, -1},
        {{1}, 10000, 10000},
    };
    for (auto& c : cases) check(sol.coinChange(c.coins, c.amount), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
