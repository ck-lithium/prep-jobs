/*
 * Split Array Largest Sum
 * LeetCode 410 (Hard) - https://leetcode.com/problems/split-array-largest-sum/
 *
 * Given an integer array `nums` and an integer `k`, split `nums` into `k`
 * non-empty contiguous parts so that the largest sum of any part is as small
 * as possible. Return that smallest possible largest sum.
 *
 * Example 1:
 *   Input:  nums = [7, 2, 5, 10, 8], k = 2
 *   Output: 18
 *   Why:    [7, 2, 5] and [10, 8] have sums 14 and 18; no split does better.
 *
 * Example 2:
 *   Input:  nums = [1, 2, 3, 4, 5], k = 2
 *   Output: 9
 *   Why:    [1, 2, 3] and [4, 5].
 *
 * Constraints:
 *   1 <= nums.length <= 1000
 *   0 <= nums[i] <= 10^6
 *   1 <= k <= min(50, nums.length)
 *
 * Target: O(n log(sum)). It's the initial set's problem 05 (ship packages
 * within D days) under another name. Spotting that is the whole point.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_splitArrayLargestSum.cpp && ./a.out
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
        {{7, 2, 5, 10, 8}, 2, 18},
        {{1, 2, 3, 4, 5}, 2, 9},
        {{1, 4, 4}, 3, 4},
        {{10}, 1, 10},
        {{1, 2, 3, 4, 5}, 1, 15},
        {{1, 2, 3, 4, 5}, 5, 5},
        {{0, 0, 0}, 2, 0},
        {{2, 3, 1, 2, 4, 3}, 5, 4},
    };
    for (auto& c : cases) check(sol.splitArray(c.nums, c.k), c.expected);

    // Big input: 1000 values of 10^6 split into 50 parts of 20: 2 * 10^7 each.
    vector<int> big(1000, 1000000);
    check(sol.splitArray(big, 50), 20000000);

    cout << passed << "/" << total << " tests passed\n";
}
