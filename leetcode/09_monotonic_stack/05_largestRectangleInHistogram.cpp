/*
 * Largest Rectangle in Histogram
 * LeetCode 84 (Hard) - https://leetcode.com/problems/largest-rectangle-in-histogram/
 *
 * `heights` describes a histogram whose bars are all 1 unit wide. Return the
 * area of the largest rectangle that fits entirely inside the histogram.
 *
 * Example 1:
 *   Input:  heights = [2, 1, 5, 6, 2, 3]
 *   Output: 10
 *   Why:    the bars of height 5 and 6 hold a 5 x 2 rectangle.
 *
 * Example 2:
 *   Input:  heights = [2, 4]
 *   Output: 4
 *
 * Constraints:
 *   1 <= heights.length <= 10^5
 *   0 <= heights[i] <= 10^4
 *
 * Target: O(n). For each bar, the widest rectangle of exactly its height
 * stretches to the nearest lower bar on each side: that's "next smaller
 * element" twice, or a single pass with a stack of increasing heights.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_largestRectangleInHistogram.cpp && ./a.out
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

    struct Case { vector<int> heights; int expected; };
    vector<Case> cases = {
        {{2, 1, 5, 6, 2, 3}, 10},
        {{2, 4}, 4},
        {{1}, 1},
        {{0}, 0},
        {{2, 2, 2}, 6},
        {{1, 2, 3, 4, 5}, 9},
        {{5, 4, 1, 2}, 8},
        {{6, 2, 5, 4, 5, 1, 6}, 12},
    };
    for (auto& c : cases) check(sol.largestRectangleArea(c.heights), c.expected);

    // Big input: 10^5 bars of height 10^4: the whole histogram, area 10^9.
    // Trying every pair of edges (O(n^2)) takes several seconds here.
    vector<int> big(100000, 10000);
    check(sol.largestRectangleArea(big), 1000000000);

    cout << passed << "/" << total << " tests passed\n";
}
