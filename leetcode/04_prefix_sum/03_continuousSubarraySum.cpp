/*
 * Continuous Subarray Sum
 * LeetCode 523 (Medium) - https://leetcode.com/problems/continuous-subarray-sum/
 *
 * Given an integer array `nums` and an integer `k`, return true if `nums` has
 * a contiguous subarray of length at least 2 whose sum is a multiple of `k`
 * (that is, sum = n * k for some integer n; 0 counts as a multiple).
 *
 * Example 1:
 *   Input:  nums = [23, 2, 4, 6, 7], k = 6
 *   Output: true
 *   Why:    [2, 4] sums to 6.
 *
 * Example 2:
 *   Input:  nums = [23, 2, 6, 4, 7], k = 6
 *   Output: true
 *   Why:    the whole array sums to 42 = 7 * 6.
 *
 * Example 3:
 *   Input:  nums = [23, 2, 6, 4, 7], k = 13
 *   Output: false
 *
 * Constraints:
 *   1 <= nums.length <= 10^5
 *   0 <= nums[i] <= 10^9
 *   0 <= sum(nums) <= 2^31 - 1
 *   1 <= k <= 2^31 - 1
 *
 * Target: O(n) time. Hint: if two prefix sums leave the same remainder when
 * divided by k, the elements between them sum to a multiple of k.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_continuousSubarraySum.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { vector<int> nums; int k; bool expected; };
    vector<Case> cases = {
        {{23, 2, 4, 6, 7}, 6, true},
        {{23, 2, 6, 4, 7}, 6, true},
        {{23, 2, 6, 4, 7}, 13, false},
        {{0}, 1, false},              // a single element is too short
        {{0, 0}, 1, true},
        {{5, 0, 0, 0}, 3, true},      // [0, 0] sums to 0
        {{1, 2, 12}, 6, false},
        {{1, 0}, 2, false},
        {{2, 4, 3}, 6, true},
        {{1, 1}, 2, true},
        {{6}, 6, false},              // a multiple, but only one element
    };
    for (auto& c : cases) check(sol.checkSubarraySum(c.nums, c.k), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
