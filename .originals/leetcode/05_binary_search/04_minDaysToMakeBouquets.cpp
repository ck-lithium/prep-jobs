/*
 * Minimum Number of Days to Make m Bouquets
 * LeetCode 1482 (Medium) - https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 *
 * A garden has n flowers in a row. Flower i blooms on day bloomDay[i] and
 * stays bloomed after that.
 *
 * You want to make `m` bouquets. Each bouquet needs `k` bloomed flowers that
 * are next to each other in the row, and each flower can go into at most one
 * bouquet.
 *
 * Return the minimum number of days you have to wait to make all `m`
 * bouquets, or -1 if it's impossible.
 *
 * Example 1:
 *   Input:  bloomDay = [1, 10, 3, 10, 2], m = 3, k = 1
 *   Output: 3
 *   Why:    on day 3, flowers 0, 2 and 4 have bloomed: three bouquets of one.
 *
 * Example 2:
 *   Input:  bloomDay = [1, 10, 3, 10, 2], m = 3, k = 2
 *   Output: -1
 *   Why:    that needs 6 flowers, and there are only 5.
 *
 * Example 3:
 *   Input:  bloomDay = [7, 7, 7, 7, 12, 7, 7], m = 2, k = 3
 *   Output: 12
 *   Why:    on day 7 only one group of 3 neighbours has bloomed
 *           ([7,7,7,7,x,7,7]); on day 12 all have.
 *
 * Constraints:
 *   1 <= bloomDay.length <= 10^5
 *   1 <= bloomDay[i] <= 10^9
 *   1 <= m <= 10^6
 *   1 <= k <= bloomDay.length
 *
 * Target: O(n log(max day)). Careful: m * k can be up to 10^11.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_minDaysToMakeBouquets.cpp && ./a.out
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

    struct Case { vector<int> bloomDay; int m, k; int expected; };
    vector<Case> cases = {
        {{1, 10, 3, 10, 2}, 3, 1, 3},
        {{1, 10, 3, 10, 2}, 3, 2, -1},
        {{7, 7, 7, 7, 12, 7, 7}, 2, 3, 12},
        {{1000000000, 1000000000}, 1, 1, 1000000000},
        {{1, 10, 2, 9, 3, 8, 4, 7, 5, 6}, 4, 2, 9},
        {{5}, 1, 1, 5},
        {{1, 2, 3, 4, 5}, 1, 5, 5},
        {{5, 4, 3, 2, 1}, 2, 2, 4},
        {{1, 2, 3}, 1000000, 3, -1},
    };
    for (auto& c : cases) check(sol.minDays(c.bloomDay, c.m, c.k), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
