/*
 * 05 - BINARY SEARCH ON THE ANSWER: Capacity To Ship Packages Within D Days
 * LeetCode 1011 (Medium) - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 *
 * Packages on a conveyor belt must all be shipped within `days` days.
 * weights[i] is the weight of the i-th package on the belt.
 *
 * Each day, the ship is loaded with the next packages on the belt, in order:
 * you can't reorder them or skip any. The total weight loaded on a single day
 * can't be more than the ship's capacity.
 *
 * Return the smallest ship capacity that lets you ship every package within
 * `days` days.
 *
 * Example 1:
 *   Input:  weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5
 *   Output: 15
 *   Why:    day 1: 1, 2, 3, 4, 5   day 2: 6, 7   day 3: 8   day 4: 9   day 5: 10
 *           With capacity 14 there is no way to do it in 5 days.
 *
 * Example 2:
 *   Input:  weights = [3, 2, 2, 4, 1, 4], days = 3
 *   Output: 6
 *   Why:    day 1: 3, 2   day 2: 2, 4   day 3: 1, 4
 *
 * Example 3:
 *   Input:  weights = [1, 2, 3, 1, 1], days = 4
 *   Output: 3
 *   Why:    day 1: 1, 2   day 2: 3   day 3: 1, 1   (finishing early is fine)
 *
 * Constraints:
 *   1 <= days <= weights.length <= 5 * 10^4
 *   1 <= weights[i] <= 500
 *
 * Target: O(n * log(sum of weights)) time.
 *
 * How to spot this pattern: "find the minimum X such that <it is possible>" (or
 * the maximum X). Checking one candidate X is easy, and if X works then every
 * bigger X also works. Very common in Amazon OAs (capacity, speed, time limits).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_binarySearchOnAnswer_shipWithinDays.cpp && ./a.out
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

    struct Case { vector<int> weights; int days; int expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5, 15},
        {{3, 2, 2, 4, 1, 4}, 3, 6},
        {{1, 2, 3, 1, 1}, 4, 3},
        {{5, 5, 5, 5}, 4, 5},
        {{5, 5, 5, 5}, 1, 20},
        {{500}, 1, 500},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1, 55},
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10},
    };
    for (auto& c : cases) check(sol.shipWithinDays(c.weights, c.days), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
