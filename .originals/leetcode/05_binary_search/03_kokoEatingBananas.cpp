/*
 * Koko Eating Bananas
 * LeetCode 875 (Medium) - https://leetcode.com/problems/koko-eating-bananas/
 *
 * Koko has piles of bananas: piles[i] bananas in pile i. The guards come back
 * in `h` hours.
 *
 * She eats at a fixed speed of k bananas per hour. Each hour she picks one
 * pile and eats k bananas from it. If the pile has fewer than k, she finishes
 * it and doesn't eat anything else that hour.
 *
 * Return the smallest integer speed k that lets her eat every banana within
 * `h` hours.
 *
 * Example 1:
 *   Input:  piles = [3, 6, 7, 11], h = 8
 *   Output: 4
 *   Why:    at speed 4 the piles take 1 + 2 + 2 + 3 = 8 hours.
 *
 * Example 2:
 *   Input:  piles = [30, 11, 23, 4, 20], h = 5
 *   Output: 30
 *
 * Example 3:
 *   Input:  piles = [30, 11, 23, 4, 20], h = 6
 *   Output: 23
 *
 * Constraints:
 *   1 <= piles.length <= 10^4
 *   piles.length <= h <= 10^9
 *   1 <= piles[i] <= 10^9
 *
 * Target: O(n log(max pile)). Watch the total hours: at speed 1 they can reach
 * 10^4 * 10^9, which doesn't fit in an int.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_kokoEatingBananas.cpp && ./a.out
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

    struct Case { vector<int> piles; int h; int expected; };
    vector<Case> cases = {
        {{3, 6, 7, 11}, 8, 4},
        {{30, 11, 23, 4, 20}, 5, 30},
        {{30, 11, 23, 4, 20}, 6, 23},
        {{1}, 1, 1},
        {{1000000000}, 2, 500000000},
        {{312884470}, 312884469, 2},
        {{1000000000, 1000000000}, 3, 1000000000},
        {{2, 2}, 2, 2},
    };
    for (auto& c : cases) check(sol.minEatingSpeed(c.piles, c.h), c.expected);

    // Big input: 10^4 piles of 10^9 bananas, h = 10^9. Speed 10000 needs exactly
    // 10^4 * 10^5 = 10^9 hours; speed 9999 needs a little more.
    vector<int> big(10000, 1000000000);
    check(sol.minEatingSpeed(big, 1000000000), 10000);

    cout << passed << "/" << total << " tests passed\n";
}
