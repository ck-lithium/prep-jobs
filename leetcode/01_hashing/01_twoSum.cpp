/*
 * Two Sum
 * LeetCode 1 (Easy) - https://leetcode.com/problems/two-sum/
 *
 * Given an array of integers `nums` and an integer `target`, return the indices
 * of the two numbers that add up to `target`.
 *
 * There is exactly one valid answer, and you can't use the same element twice.
 * You can return the two indices in any order.
 *
 * Example 1:
 *   Input:  nums = [2, 7, 11, 15], target = 9
 *   Output: [0, 1]
 *   Why:    nums[0] + nums[1] = 2 + 7 = 9.
 *
 * Example 2:
 *   Input:  nums = [3, 2, 4], target = 6
 *   Output: [1, 2]
 *
 * Example 3:
 *   Input:  nums = [3, 3], target = 6
 *   Output: [0, 1]
 *
 * Constraints:
 *   2 <= nums.length <= 10^4
 *   -10^9 <= nums[i], target <= 10^9
 *   Exactly one valid answer exists.
 *
 * Target: O(n) time.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_twoSum.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { vector<int> nums; int target; vector<int> expected; };
    vector<Case> cases = {
        {{2, 7, 11, 15}, 9, {0, 1}},
        {{3, 2, 4}, 6, {1, 2}},
        {{3, 3}, 6, {0, 1}},
        {{-3, 4, 3, 90}, 0, {0, 2}},
        {{0, 4, 3, 0}, 0, {0, 3}},
        {{-1, -2, -3, -4, -5}, -8, {2, 4}},
        {{1000000000, 5, -1000000000}, 0, {0, 2}},
    };
    for (auto& c : cases) {
        // Any order is accepted, so sort the answer before comparing.
        auto got = sol.twoSum(c.nums, c.target);
        sort(got.begin(), got.end());
        check(got, c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
