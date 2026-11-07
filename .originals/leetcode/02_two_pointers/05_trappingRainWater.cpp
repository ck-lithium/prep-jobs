/*
 * Trapping Rain Water
 * LeetCode 42 (Hard) - https://leetcode.com/problems/trapping-rain-water/
 *
 * `height` describes a row of bars, each 1 unit wide: bar i is height[i] tall.
 * After it rains, water collects between the bars. Return how many units of
 * water are trapped.
 *
 * The water above bar i rises to the lower of the tallest bar on its left and
 * the tallest bar on its right, so it holds
 *   min(max(height[0..i]), max(height[i..n-1])) - height[i]
 * units.
 *
 * Example 1:
 *   Input:  height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
 *   Output: 6
 *
 *   3 |               #
 *   2 |       # ~ ~ ~ # # ~ #
 *   1 |   # ~ # # ~ # # # # # #
 *     +-------------------------
 *
 * Example 2:
 *   Input:  height = [4, 2, 0, 3, 2, 5]
 *   Output: 9
 *
 * Constraints:
 *   1 <= height.length <= 2 * 10^4
 *   0 <= height[i] <= 10^5
 *
 * Target: O(n) time. Prefix and suffix maximums give O(n) space; two pointers
 * get it down to O(1).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_trappingRainWater.cpp && ./a.out
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

    struct Case { vector<int> height; int expected; };
    vector<Case> cases = {
        {{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
        {{4, 2, 0, 3, 2, 5}, 9},
        {{1}, 0},
        {{2, 0, 2}, 2},
        {{3, 0, 0, 2, 0, 4}, 10},
        {{5, 4, 3, 2, 1}, 0},
        {{0, 0, 0}, 0},
        {{4, 2, 3}, 1},
    };
    for (auto& c : cases) check(sol.trap(c.height), c.expected);

    // Big input: 20000 bars alternating 100000, 0, 100000, 0, ... Every 0 that
    // has a wall on both sides fills up: 9999 of them, 100000 units each.
    // An O(n^2) solution takes about 0.2 s here; an O(n) one, under 1 ms.
    vector<int> big(20000);
    for (int i = 0; i < 20000; i++) big[i] = (i % 2 == 0) ? 100000 : 0;
    check(sol.trap(big), 999900000);

    cout << passed << "/" << total << " tests passed\n";
}
