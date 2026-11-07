/*
 * Jump Game
 * LeetCode 55 (Medium) - https://leetcode.com/problems/jump-game/
 *
 * You start at index 0 of the array `nums`. From index i you can jump forward
 * by any distance from 1 to nums[i]. Return true if you can reach the last
 * index.
 *
 * Example 1:
 *   Input:  nums = [2, 3, 1, 1, 4]
 *   Output: true
 *   Why:    jump 1 step to index 1, then 3 steps to the last index.
 *
 * Example 2:
 *   Input:  nums = [3, 2, 1, 0, 4]
 *   Output: false
 *   Why:    every path ends up at index 3, where the jump length is 0.
 *
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   0 <= nums[i] <= 10^5
 *
 * Target: O(n), one pass. Keep track of the farthest index you can reach so
 * far.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_jumpGame.cpp && ./a.out
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

    struct Case { vector<int> nums; bool expected; };
    vector<Case> cases = {
        {{2, 3, 1, 1, 4}, true},
        {{3, 2, 1, 0, 4}, false},
        {{0}, true},              // already at the last index
        {{0, 1}, false},
        {{1, 0}, true},
        {{2, 0, 0}, true},
        {{1, 1, 0, 1}, false},
        {{5, 0, 0, 0, 0, 0}, true},
        {{2, 5, 0, 0}, true},
    };
    for (auto& c : cases) check(sol.canJump(c.nums), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
