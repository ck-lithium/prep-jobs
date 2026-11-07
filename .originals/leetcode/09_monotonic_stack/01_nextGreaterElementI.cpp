/*
 * Next Greater Element I
 * LeetCode 496 (Easy) - https://leetcode.com/problems/next-greater-element-i/
 *
 * The "next greater element" of x in an array is the first element to the
 * right of x that is larger than x.
 *
 * You are given two arrays of distinct integers, `nums1` and `nums2`, where
 * every value of nums1 also appears in nums2. For each value in nums1, find
 * its next greater element in nums2, or -1 if it has none.
 *
 * Example 1:
 *   Input:  nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2]
 *   Output: [-1, 3, -1]
 *   Why:    in nums2, nothing after 4 is bigger; after 1 comes 3; nothing
 *           after 2.
 *
 * Example 2:
 *   Input:  nums1 = [2, 4], nums2 = [1, 2, 3, 4]
 *   Output: [3, -1]
 *
 * Constraints:
 *   1 <= nums1.length <= nums2.length <= 1000
 *   0 <= nums1[i], nums2[i] <= 10^4
 *   All values in each array are different, and nums1 is a subset of nums2.
 *
 * Target: O(nums1.length + nums2.length). One pass over nums2 with a stack
 * finds every next greater element; a hash map then answers each query.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_nextGreaterElementI.cpp && ./a.out
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

    struct Case { vector<int> nums1, nums2; vector<int> expected; };
    vector<Case> cases = {
        {{4, 1, 2}, {1, 3, 4, 2}, {-1, 3, -1}},
        {{2, 4}, {1, 2, 3, 4}, {3, -1}},
        {{1}, {1}, {-1}},
        {{3, 1, 5}, {6, 5, 4, 3, 2, 1, 7}, {7, 7, 7}},
        {{1, 3}, {1, 3, 2}, {3, -1}},
        {{2}, {2, 1, 3}, {3}},
    };
    for (auto& c : cases) check(sol.nextGreaterElement(c.nums1, c.nums2), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
