/*
 * 04 - PREFIX SUM: Subarray Sum Equals K
 * LeetCode 560 (Medium) - https://leetcode.com/problems/subarray-sum-equals-k/
 *
 * Given an integer array `nums` and an integer `k`, return how many contiguous,
 * non-empty subarrays have a sum exactly equal to `k`.
 *
 * Note that `nums` can contain negative numbers and zeros.
 *
 * Example 1:
 *   Input:  nums = [1, 1, 1], k = 2
 *   Output: 2
 *   Why:    [1, 1] starting at index 0, and [1, 1] starting at index 1.
 *
 * Example 2:
 *   Input:  nums = [1, 2, 3], k = 3
 *   Output: 2
 *   Why:    [1, 2] and [3].
 *
 * Example 3:
 *   Input:  nums = [1, -1, 0], k = 0
 *   Output: 3
 *   Why:    [1, -1], [0] and [1, -1, 0].
 *
 * Constraints:
 *   1 <= nums.length <= 2 * 10^4
 *   -1000 <= nums[i] <= 1000
 *   -10^7 <= k <= 10^7
 *
 * Target: O(n) time.
 *
 * How to spot this pattern: "count / find subarrays whose sum is exactly X".
 * If values can be negative, a sliding window won't work; a prefix sum will.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_prefixSum_subarraySumEqualsK.cpp && ./a.out
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
        {{1, 1, 1}, 2, 2},
        {{1, 2, 3}, 3, 2},
        {{1, -1, 0}, 0, 3},
        {{3, 4, 7, 2, -3, 1, 4, 2}, 7, 4},
        {{1}, 0, 0},
        {{0, 0, 0}, 0, 6},
        {{-1, -1, 1}, 0, 1},
    };
    for (auto& c : cases) check(sol.subarraySum(c.nums, c.k), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
