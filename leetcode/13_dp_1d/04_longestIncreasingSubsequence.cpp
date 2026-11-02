/*
 * Longest Increasing Subsequence
 * LeetCode 300 (Medium) - https://leetcode.com/problems/longest-increasing-subsequence/
 *
 * Given an integer array `nums`, return the length of its longest strictly
 * increasing subsequence. A subsequence keeps the original order but can skip
 * elements: [3, 6, 2, 7] has the subsequence [3, 6, 7].
 *
 * Example 1:
 *   Input:  nums = [10, 9, 2, 5, 3, 7, 101, 18]
 *   Output: 4
 *   Why:    [2, 3, 7, 101] (or [2, 5, 7, 18], ...).
 *
 * Example 2:
 *   Input:  nums = [0, 1, 0, 3, 2, 3]
 *   Output: 4
 *
 * Example 3:
 *   Input:  nums = [7, 7, 7, 7, 7, 7, 7]
 *   Output: 1
 *   Why:    strictly increasing, so equal values don't count.
 *
 * Constraints:
 *   1 <= nums.length <= 2500
 *   -10^4 <= nums[i] <= 10^4
 *
 * Target: O(n^2) first: best[i] = longest increasing subsequence ending at i.
 * Follow-up: O(n log n) by keeping, for every length, the smallest value an
 * increasing subsequence of that length can end with, and binary searching it.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_longestIncreasingSubsequence.cpp && ./a.out
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

    struct Case { vector<int> nums; int expected; };
    vector<Case> cases = {
        {{10, 9, 2, 5, 3, 7, 101, 18}, 4},
        {{0, 1, 0, 3, 2, 3}, 4},
        {{7, 7, 7, 7, 7, 7, 7}, 1},
        {{1}, 1},
        {{1, 2}, 2},
        {{2, 1}, 1},
        {{4, 10, 4, 3, 8, 9}, 3},
        {{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12}, 6},
    };
    for (auto& c : cases) check(sol.lengthOfLIS(c.nums), c.expected);

    // Big input: 2500 values going down by 1 and up by 2: 0, -1, 2, 1, 4, 3, ...
    // Every other one is part of the answer: 1250.
    vector<int> big(2500);
    for (int i = 0; i < 2500; i++) big[i] = (i % 2 == 0) ? i : i - 2;
    check(sol.lengthOfLIS(big), 1250);

    cout << passed << "/" << total << " tests passed\n";
}
