/*
 * House Robber
 * LeetCode 198 (Medium) - https://leetcode.com/problems/house-robber/
 *
 * A row of houses holds nums[i] money in house i. You want to take as much as
 * possible, but if you take from two houses next to each other, an alarm goes
 * off. Return the most money you can take without ever taking from two
 * neighbouring houses.
 *
 * Example 1:
 *   Input:  nums = [1, 2, 3, 1]
 *   Output: 4
 *   Why:    houses 0 and 2: 1 + 3.
 *
 * Example 2:
 *   Input:  nums = [2, 7, 9, 3, 1]
 *   Output: 12
 *   Why:    houses 0, 2 and 4: 2 + 9 + 1.
 *
 * Constraints:
 *   1 <= nums.length <= 100
 *   0 <= nums[i] <= 400
 *
 * Target: O(n) time, O(1) space. For each house, the best total so far either
 * skips it or takes it plus the best total two houses back.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_houseRobber.cpp && ./a.out
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
        {{1, 2, 3, 1}, 4},
        {{2, 7, 9, 3, 1}, 12},
        {{5}, 5},
        {{2, 1}, 2},
        {{2, 1, 1, 2}, 4},          // skipping two in a row can pay off
        {{0, 0, 0}, 0},
        {{10, 1, 1, 10}, 20},
        {{1, 3, 1}, 3},
    };
    for (auto& c : cases) check(sol.rob(c.nums), c.expected);

    // Big input: 100 houses of 400. Trying every subset of houses never ends.
    vector<int> big(100, 400);
    check(sol.rob(big), 20000);

    cout << passed << "/" << total << " tests passed\n";
}
