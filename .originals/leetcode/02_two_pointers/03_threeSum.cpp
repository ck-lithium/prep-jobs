/*
 * 3Sum
 * LeetCode 15 (Medium) - https://leetcode.com/problems/3sum/
 *
 * Given an integer array `nums`, return every triplet [nums[i], nums[j], nums[k]]
 * whose three values add up to 0, where i, j and k are different positions.
 *
 * The answer must not contain the same triplet twice (two triplets are the same
 * if they hold the same three values). Return the triplets in any order.
 *
 * Example 1:
 *   Input:  nums = [-1, 0, 1, 2, -1, -4]
 *   Output: [[-1, -1, 2], [-1, 0, 1]]
 *
 * Example 2:
 *   Input:  nums = [0, 1, 1]
 *   Output: []
 *
 * Example 3:
 *   Input:  nums = [0, 0, 0]
 *   Output: [[0, 0, 0]]
 *
 * Constraints:
 *   3 <= nums.length <= 3000
 *   -10^5 <= nums[i] <= 10^5
 *
 * Target: O(n^2) time. Sort first, then fix one number and run two pointers
 * over the rest. The hard part is skipping duplicates correctly.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_threeSum.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

// Any order is accepted, so sort inside each triplet and then sort the list.
vector<vector<int>> normalize(vector<vector<int>> triplets) {
    for (auto& t : triplets) sort(t.begin(), t.end());
    sort(triplets.begin(), triplets.end());
    return triplets;
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

    struct Case { vector<int> nums; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}}},
        {{0, 1, 1}, {}},
        {{0, 0, 0}, {{0, 0, 0}}},
        {{0, 0, 0, 0}, {{0, 0, 0}}},
        {{-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}}},
        {{1, 2, -2, -1}, {}},
        {{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6},
         {{-4, -2, 6}, {-4, 0, 4}, {-4, 1, 3}, {-4, 2, 2}, {-2, -2, 4}, {-2, 0, 2}}},
    };
    for (auto& c : cases) check(normalize(sol.threeSum(c.nums)), normalize(c.expected));

    cout << passed << "/" << total << " tests passed\n";
}
