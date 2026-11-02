/*
 * Product of Array Except Self
 * LeetCode 238 (Medium) - https://leetcode.com/problems/product-of-array-except-self/
 *
 * Given an integer array `nums`, return an array `answer` where answer[i] is
 * the product of every element of `nums` except nums[i].
 *
 * Don't use division (it would also break on zeros).
 *
 * Example 1:
 *   Input:  nums = [1, 2, 3, 4]
 *   Output: [24, 12, 8, 6]
 *
 * Example 2:
 *   Input:  nums = [-1, 1, 0, -3, 3]
 *   Output: [0, 0, 9, 0, 0]
 *
 * Constraints:
 *   2 <= nums.length <= 10^5
 *   -30 <= nums[i] <= 30
 *   Every product of any prefix or suffix of nums fits in a 32-bit int.
 *
 * Target: O(n) time. Follow-up: O(1) extra space besides the output array.
 * Hint: answer[i] = (product of everything left of i) * (product of
 * everything right of i). Those are prefix and suffix products.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_productOfArrayExceptSelf.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }
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
        {{1, 2, 3, 4}, {24, 12, 8, 6}},
        {{-1, 1, 0, -3, 3}, {0, 0, 9, 0, 0}},
        {{2, 3}, {3, 2}},
        {{0, 0}, {0, 0}},
        {{0, 4, 5}, {20, 0, 0}},
        {{1, 1, 1, 1}, {1, 1, 1, 1}},
        {{-2, -3, 4}, {-12, -8, 6}},
    };
    for (auto& c : cases) check(sol.productExceptSelf(c.nums), c.expected);

    // Big input: 100000 ones, except nums[0] = -1. An O(n^2) solution takes
    // far too long here. (Prints true/false only.)
    vector<int> big(100000, 1);
    big[0] = -1;
    vector<int> bigExpected(100000, -1);
    bigExpected[0] = 1;
    check(sol.productExceptSelf(big) == bigExpected, true);

    cout << passed << "/" << total << " tests passed\n";
}
