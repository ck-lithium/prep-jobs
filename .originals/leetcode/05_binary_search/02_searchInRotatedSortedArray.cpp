/*
 * Search in Rotated Sorted Array
 * LeetCode 33 (Medium) - https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * An array of distinct integers was sorted in ascending order and then
 * possibly rotated: cut at some position, with the two parts swapped. For
 * example [0, 1, 2, 4, 5, 6, 7] rotated at position 3 becomes
 * [4, 5, 6, 7, 0, 1, 2].
 *
 * Given the rotated array `nums` and an integer `target`, return the index of
 * `target`, or -1 if it isn't in the array.
 *
 * Example 1:
 *   Input:  nums = [4, 5, 6, 7, 0, 1, 2], target = 0
 *   Output: 4
 *
 * Example 2:
 *   Input:  nums = [4, 5, 6, 7, 0, 1, 2], target = 3
 *   Output: -1
 *
 * Example 3:
 *   Input:  nums = [1], target = 0
 *   Output: -1
 *
 * Constraints:
 *   1 <= nums.length <= 5000
 *   -10^4 <= nums[i], target <= 10^4
 *   All values are different. nums is an ascending array, possibly rotated.
 *
 * Target: O(log n) time. Hint: when you split at mid, at least one of the two
 * halves is sorted normally, and you can tell which.
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
//   g++ -std=c++17 -O2 -Wall 02_searchInRotatedSortedArray.cpp && ./a.out
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
        {{4, 5, 6, 7, 0, 1, 2}, 0, 4},
        {{4, 5, 6, 7, 0, 1, 2}, 3, -1},
        {{1}, 0, -1},
        {{1}, 1, 0},
        {{3, 1}, 1, 1},
        {{3, 1}, 3, 0},
        {{5, 1, 3}, 5, 0},
        {{5, 1, 3}, 3, 2},
        {{4, 5, 6, 7, 8, 1, 2, 3}, 8, 4},
        {{1, 2, 3, 4, 5}, 4, 3},          // not rotated at all
        {{6, 7, 1, 2, 3, 4, 5}, 6, 0},
    };
    for (auto& c : cases) check(sol.search(c.nums, c.target), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
