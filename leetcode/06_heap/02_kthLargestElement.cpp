/*
 * Kth Largest Element in an Array
 * LeetCode 215 (Medium) - https://leetcode.com/problems/kth-largest-element-in-an-array/
 *
 * Given an integer array `nums` and an integer `k`, return the k-th largest
 * element: the one that would be at position k if the array were sorted from
 * largest to smallest. Duplicates count separately, so in [3, 3, 1] the 2nd
 * largest is 3.
 *
 * Try to solve it without sorting the whole array.
 *
 * Example 1:
 *   Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
 *   Output: 5
 *
 * Example 2:
 *   Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
 *   Output: 4
 *
 * Constraints:
 *   1 <= k <= nums.length <= 10^5
 *   -10^4 <= nums[i] <= 10^4
 *
 * Target: O(n log k) with a min-heap of size k. (Quickselect averages O(n),
 * worth trying second.)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_kthLargestElement.cpp && ./a.out
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

    struct Case { vector<int> nums; int k; int expected; };
    vector<Case> cases = {
        {{3, 2, 1, 5, 6, 4}, 2, 5},
        {{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4},
        {{1}, 1, 1},
        {{2, 1}, 2, 1},
        {{7, 7, 7}, 2, 7},
        {{-1, -2, -3}, 1, -1},
        {{5, 2, 4, 1, 3, 6, 0}, 4, 3},
    };
    for (auto& c : cases) check(sol.findKthLargest(c.nums, c.k), c.expected);

    // Big input: 0..9999, each value 10 times. The 25th largest is 9997.
    vector<int> big(100000);
    for (int i = 0; i < 100000; i++) big[i] = i % 10000;
    check(sol.findKthLargest(big, 25), 9997);

    cout << passed << "/" << total << " tests passed\n";
}
