/*
 * Subarray Sums Divisible by K
 * LeetCode 974 (Medium) - https://leetcode.com/problems/subarray-sums-divisible-by-k/
 *
 * Given an integer array `nums` and an integer `k`, return how many non-empty
 * contiguous subarrays have a sum divisible by `k`.
 *
 * Example 1:
 *   Input:  nums = [4, 5, 0, -2, -3, 1], k = 5
 *   Output: 7
 *   Why:    [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3]
 *           and [-2, -3].
 *
 * Example 2:
 *   Input:  nums = [5], k = 9
 *   Output: 0
 *
 * Constraints:
 *   1 <= nums.length <= 3 * 10^4
 *   -10^4 <= nums[i] <= 10^4
 *   2 <= k <= 10^4
 *
 * Target: O(n + k) time. Careful: in C++, -7 % 5 is -2, not 3.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_subarraySumsDivisibleByK.cpp && ./a.out
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
        {{4, 5, 0, -2, -3, 1}, 5, 7},
        {{5}, 9, 0},
        {{0, 0, 0}, 3, 6},
        {{-1, 2, 9}, 2, 2},
        {{5, 5, 5}, 5, 6},
        {{1, 2, 3}, 7, 0},
        {{-5}, 5, 1},
        {{2, -2, 2, -4}, 6, 2},
    };
    for (auto& c : cases) check(sol.subarraysDivByK(c.nums, c.k), c.expected);

    // Big input: 30000 ones with k = 2. Every even-length subarray counts:
    // 29999 + 29997 + ... + 1 = 225000000 of them.
    vector<int> big(30000, 1);
    check(sol.subarraysDivByK(big, 2), 225000000);

    cout << passed << "/" << total << " tests passed\n";
}
