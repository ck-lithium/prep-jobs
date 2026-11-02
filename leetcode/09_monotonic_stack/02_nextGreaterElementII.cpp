/*
 * Next Greater Element II
 * LeetCode 503 (Medium) - https://leetcode.com/problems/next-greater-element-ii/
 *
 * Given a circular array `nums` (after the last element comes the first one
 * again), return the next greater element of every element: the first larger
 * value you meet going right, wrapping around if needed. Use -1 when there is
 * none.
 *
 * Example 1:
 *   Input:  nums = [1, 2, 1]
 *   Output: [2, -1, 2]
 *   Why:    for the last 1, the search wraps around and finds the 2.
 *
 * Example 2:
 *   Input:  nums = [1, 2, 3, 4, 3]
 *   Output: [2, 3, 4, -1, 4]
 *
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^9 <= nums[i] <= 10^9
 *
 * Target: O(n). Hint: walk the array twice (index i % n) with a stack of
 * indices still waiting for their answer.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_nextGreaterElementII.cpp && ./a.out
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
        {{1, 2, 1}, {2, -1, 2}},
        {{1, 2, 3, 4, 3}, {2, 3, 4, -1, 4}},
        {{5}, {-1}},
        {{3, 3, 3}, {-1, -1, -1}},
        {{5, 4, 3, 2, 1}, {-1, 5, 5, 5, 5}},
        {{1, 1, 2}, {2, 2, -1}},
        {{-2, 0}, {0, -1}},
        {{1000000000, -1000000000}, {-1, 1000000000}},
    };
    for (auto& c : cases) check(sol.nextGreaterElements(c.nums), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
