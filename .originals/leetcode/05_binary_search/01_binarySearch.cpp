/*
 * Binary Search
 * LeetCode 704 (Easy) - https://leetcode.com/problems/binary-search/
 *
 * Given an array `nums` of distinct integers sorted in ascending order and an
 * integer `target`, return the index of `target` in `nums`, or -1 if it isn't
 * there.
 *
 * Example 1:
 *   Input:  nums = [-1, 0, 3, 5, 9, 12], target = 9
 *   Output: 4
 *
 * Example 2:
 *   Input:  nums = [-1, 0, 3, 5, 9, 12], target = 2
 *   Output: -1
 *
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^4 < nums[i], target < 10^4
 *   All values in nums are different, and nums is sorted in ascending order.
 *
 * Target: O(log n) time. This is the plain version of the template from the
 * initial set's problem 05: get it exactly right, including the loop condition
 * and how lo and hi move, so you can write it without thinking.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_binarySearch.cpp && ./a.out
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

    struct Case { vector<int> nums; int target; int expected; };
    vector<Case> cases = {
        {{-1, 0, 3, 5, 9, 12}, 9, 4},
        {{-1, 0, 3, 5, 9, 12}, 2, -1},
        {{5}, 5, 0},
        {{5}, -5, -1},
        {{1, 3}, 3, 1},
        {{1, 3}, 1, 0},
        {{1, 3}, 2, -1},
        {{1, 3}, 4, -1},
        {{1, 3, 5, 7, 9, 11}, 0, -1},
        {{1, 3, 5, 7, 9, 11}, 11, 5},
    };
    for (auto& c : cases) check(sol.search(c.nums, c.target), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
