/*
 * Summary Ranges
 * LeetCode 228 (Easy) - https://leetcode.com/problems/summary-ranges/
 *
 * You are given a sorted array `nums` of unique integers. Describe it as the
 * shortest sorted list of ranges of consecutive numbers that covers exactly
 * the values in `nums`.
 *
 * Write each range [a, b] as "a->b", or as "a" when a == b.
 *
 * Example 1:
 *   Input:  nums = [0, 1, 2, 4, 5, 7]
 *   Output: ["0->2", "4->5", "7"]
 *
 * Example 2:
 *   Input:  nums = [0, 2, 3, 4, 6, 8, 9]
 *   Output: ["0", "2->4", "6", "8->9"]
 *
 * Constraints:
 *   0 <= nums.length <= 20
 *   -2^31 <= nums[i] <= 2^31 - 1
 *   All values are unique, and nums is sorted in ascending order.
 *
 * Target: O(n). Watch out for overflow when the values are near INT_MIN and
 * INT_MAX.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_summaryRanges.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(const string& s) { return '"' + s + '"'; }
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

    struct Case { vector<int> nums; vector<string> expected; };
    vector<Case> cases = {
        {{0, 1, 2, 4, 5, 7}, {"0->2", "4->5", "7"}},
        {{0, 2, 3, 4, 6, 8, 9}, {"0", "2->4", "6", "8->9"}},
        {{}, {}},
        {{-1}, {"-1"}},
        {{1, 3}, {"1", "3"}},
        {{-3, -2, -1, 0, 1}, {"-3->1"}},
        {{2147483646, 2147483647}, {"2147483646->2147483647"}},
        {{-2147483647 - 1, 2147483647}, {"-2147483648", "2147483647"}},
    };
    for (auto& c : cases) check(sol.summaryRanges(c.nums), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
