/*
 * Max Consecutive Ones III
 * LeetCode 1004 (Medium) - https://leetcode.com/problems/max-consecutive-ones-iii/
 *
 * Given an array `nums` of 0s and 1s and an integer `k`, return the length of
 * the longest run of consecutive 1s you can get by flipping at most `k` of the
 * 0s into 1s.
 *
 * Example 1:
 *   Input:  nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2
 *   Output: 6
 *   Why:    flip the 0s at positions 4 and 5: [1,1,1,0,1,1,1,1,1,1,0].
 *
 * Example 2:
 *   Input:  nums = [0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1], k = 3
 *   Output: 10
 *
 * Constraints:
 *   1 <= nums.length <= 10^5
 *   nums[i] is 0 or 1.
 *   0 <= k <= nums.length
 *
 * Target: O(n) time. Rephrase it first: the longest window with at most k 0s.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_maxConsecutiveOnesIII.cpp && ./a.out
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
        {{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6},
        {{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10},
        {{0, 0, 0}, 0, 0},
        {{0, 0, 0}, 5, 3},
        {{1, 1, 1}, 0, 3},
        {{1, 0, 1}, 1, 3},
        {{0}, 1, 1},
        {{1, 0, 0, 1, 0, 1, 1}, 1, 4},
    };
    for (auto& c : cases) check(sol.longestOnes(c.nums, c.k), c.expected);

    // Big input: 1, 0, 1, 0, ... (100000 values) with k = 1000. The best window
    // has 1000 zeros and the 1001 ones around them.
    vector<int> big(100000);
    for (int i = 0; i < 100000; i++) big[i] = (i % 2 == 0);
    check(sol.longestOnes(big, 1000), 2001);

    cout << passed << "/" << total << " tests passed\n";
}
