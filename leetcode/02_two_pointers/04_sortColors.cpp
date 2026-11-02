/*
 * Sort Colors
 * LeetCode 75 (Medium) - https://leetcode.com/problems/sort-colors/
 *
 * An array `nums` holds n objects coloured red, white or blue, written as
 * 0 (red), 1 (white) and 2 (blue). Sort it in place so that all the 0s come
 * first, then the 1s, then the 2s.
 *
 * Don't use the library's sort function.
 *
 * Example 1:
 *   Input:  nums = [2, 0, 2, 1, 1, 0]
 *   Output: [0, 0, 1, 1, 2, 2]
 *
 * Example 2:
 *   Input:  nums = [2, 0, 1]
 *   Output: [0, 1, 2]
 *
 * Constraints:
 *   1 <= nums.length <= 300
 *   nums[i] is 0, 1 or 2.
 *
 * Target: a single pass with O(1) extra space. Counting the colours and then
 * rewriting the array takes two passes: start there, then try with three
 * pointers (this is the "Dutch national flag" problem).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // TODO
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_sortColors.cpp && ./a.out
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

    struct Case { vector<int> nums; vector<int> expected; };
    vector<Case> cases = {
        {{2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2}},
        {{2, 0, 1}, {0, 1, 2}},
        {{0}, {0}},
        {{1, 0}, {0, 1}},
        {{2, 2, 2}, {2, 2, 2}},
        {{1, 2, 0, 0, 2, 1, 0, 1}, {0, 0, 0, 1, 1, 1, 2, 2}},
        {{2, 1, 0, 2, 1, 0}, {0, 0, 1, 1, 2, 2}},
        {{1, 1, 0, 0}, {0, 0, 1, 1}},
    };
    for (auto& c : cases) {
        sol.sortColors(c.nums);
        check(c.nums, c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
