/*
 * Two Sum II - Input Array Is Sorted
 * LeetCode 167 (Medium) - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 *
 * You are given an array `numbers` sorted in non-decreasing order, and an
 * integer `target`. Find the two numbers that add up to `target` and return
 * their positions as [index1, index2], counting from 1, with index1 < index2.
 *
 * There is exactly one answer, and you can't use the same element twice.
 *
 * Example 1:
 *   Input:  numbers = [2, 7, 11, 15], target = 9
 *   Output: [1, 2]
 *
 * Example 2:
 *   Input:  numbers = [2, 3, 4], target = 6
 *   Output: [1, 3]
 *
 * Example 3:
 *   Input:  numbers = [-1, 0], target = -1
 *   Output: [1, 2]
 *
 * Constraints:
 *   2 <= numbers.length <= 3 * 10^4
 *   -1000 <= numbers[i], target <= 1000
 *   numbers is sorted in non-decreasing order.
 *   Exactly one answer exists.
 *
 * Target: O(n) time, O(1) extra space (so no hash map this time).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_twoSumII.cpp && ./a.out
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

    struct Case { vector<int> numbers; int target; vector<int> expected; };
    vector<Case> cases = {
        {{2, 7, 11, 15}, 9, {1, 2}},
        {{2, 3, 4}, 6, {1, 3}},
        {{-1, 0}, -1, {1, 2}},
        {{1, 2, 3, 4, 4, 9, 56, 90}, 8, {4, 5}},
        {{5, 25, 75}, 100, {2, 3}},
        {{0, 0, 3, 4}, 0, {1, 2}},
        {{-3, -1, 0, 2, 5}, 4, {2, 5}},
    };
    for (auto& c : cases) check(sol.twoSum(c.numbers, c.target), c.expected);

    // Big input: 29998 zeros, then 500 and 1000. Only 500 + 1000 = 1500.
    vector<int> big(29998, 0);
    big.push_back(500);
    big.push_back(1000);
    check(sol.twoSum(big, 1500), vector<int>{29999, 30000});

    cout << passed << "/" << total << " tests passed\n";
}
