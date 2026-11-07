/*
 * First Missing Positive
 * LeetCode 41 (Hard) - https://leetcode.com/problems/first-missing-positive/
 *
 * Given an unsorted integer array `nums`, return the smallest positive integer
 * (1, 2, 3, ...) that does not appear in it.
 *
 * Example 1:
 *   Input:  nums = [1, 2, 0]
 *   Output: 3
 *
 * Example 2:
 *   Input:  nums = [3, 4, -1, 1]
 *   Output: 2
 *
 * Example 3:
 *   Input:  nums = [7, 8, 9, 11, 12]
 *   Output: 1
 *
 * Constraints:
 *   1 <= nums.length <= 10^5
 *   -2^31 <= nums[i] <= 2^31 - 1
 *
 * Target: O(n) time and O(1) extra space. You may modify `nums`.
 * (A hash set gives O(n) time with O(n) space: solve that first, then think
 * about using the array itself as the hash table.)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_firstMissingPositive.cpp && ./a.out
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
        {{1, 2, 0}, 3},
        {{3, 4, -1, 1}, 2},
        {{7, 8, 9, 11, 12}, 1},
        {{1}, 2},
        {{2}, 1},
        {{1, 1}, 2},
        {{INT_MAX, INT_MIN}, 1},
        {{2, 3, 4, 5, 1}, 6},
        {{0, -1, 3, 1, 2, 2}, 4},
    };
    for (auto& c : cases) check(sol.firstMissingPositive(c.nums), c.expected);

    // Big input: 100000, 99999, ..., 1, so the answer is 100001.
    vector<int> big(100000);
    for (int i = 0; i < 100000; i++) big[i] = 100000 - i;
    check(sol.firstMissingPositive(big), 100001);

    cout << passed << "/" << total << " tests passed\n";
}
