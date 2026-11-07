/*
 * 01 - HASHING: Longest Consecutive Sequence
 * LeetCode 128 (Medium) - https://leetcode.com/problems/longest-consecutive-sequence/
 *
 * You are given an unsorted array of integers `nums`. Return the length of the
 * longest run of consecutive values (x, x+1, x+2, ...) that all appear in `nums`.
 * The values don't need to be next to each other in the array, and a value that
 * appears more than once only counts once.
 *
 * Your algorithm must run in O(n) time.
 *
 * Example 1:
 *   Input:  nums = [100, 4, 200, 1, 3, 2]
 *   Output: 4
 *   Why:    the longest run is 1, 2, 3, 4.
 *
 * Example 2:
 *   Input:  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
 *   Output: 9
 *   Why:    every value from 0 to 8 is present.
 *
 * Example 3:
 *   Input:  nums = [1, 0, 1, 2]
 *   Output: 3
 *
 * Constraints:
 *   0 <= nums.length <= 10^5
 *   -10^9 <= nums[i] <= 10^9
 *
 * Target: O(n) time.
 *
 * How to spot this pattern: you keep asking "is value X in the input?" and need
 * the answer in O(1), or sorting is ruled out.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_hashing_longestConsecutiveSequence.cpp && ./a.out
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
        {{100, 4, 200, 1, 3, 2}, 4},
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},
        {{1, 0, 1, 2}, 3},
        {{}, 0},
        {{5}, 1},
        {{-1, -2, -3, 10, 11}, 3},
        {{1000000000, -1000000000}, 1},
    };
    for (auto& c : cases) check(sol.longestConsecutive(c.nums), c.expected);

    // Big input: 10^5 values. An O(n^2) solution will take many seconds here.
    vector<int> big(100000);
    iota(big.rbegin(), big.rend(), 0);  // 99999, 99998, ..., 0
    check(sol.longestConsecutive(big), 100000);

    cout << passed << "/" << total << " tests passed\n";
}
