/*
 * Subsets
 * LeetCode 78 (Medium) - https://leetcode.com/problems/subsets/
 *
 * Given an array of distinct integers, return all of its subsets (the "power
 * set"), including the empty one and the whole array. No subset may appear
 * twice. Return them in any order.
 *
 * Example 1:
 *   Input:  nums = [1, 2, 3]
 *   Output: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
 *
 * Example 2:
 *   Input:  nums = [0]
 *   Output: [[], [0]]
 *
 * Constraints:
 *   1 <= nums.length <= 10
 *   -10 <= nums[i] <= 10
 *   All values are different.
 *
 * Target: O(n * 2^n), which is the size of the answer. The backtracking
 * template: for each element, explore "take it" and "leave it", and undo the
 * choice when you come back.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_subsets.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
string str(const string& s) { return s; }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

// Any order is accepted, so sort inside each subset and then sort the list.
vector<vector<int>> normalize(vector<vector<int>> sets) {
    for (auto& s : sets) sort(s.begin(), s.end());
    sort(sets.begin(), sets.end());
    return sets;
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

    struct Case { vector<int> nums; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{1, 2, 3}, {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}},
        {{0}, {{}, {0}}},
        {{5, -1}, {{}, {-1}, {5}, {-1, 5}}},
    };
    for (auto& c : cases) check(normalize(sol.subsets(c.nums)), normalize(c.expected));

    // Ten numbers: there must be 2^10 = 1024 different subsets, each using
    // only the given numbers, each at most once.
    vector<int> ten = {-10, -7, -3, -1, 0, 2, 4, 6, 8, 10};
    auto got = normalize(sol.subsets(ten));
    bool ok = got.size() == 1024 && adjacent_find(got.begin(), got.end()) == got.end();
    for (auto& s : got) ok &= includes(ten.begin(), ten.end(), s.begin(), s.end()) &&
                              adjacent_find(s.begin(), s.end()) == s.end();
    check(string(ok ? "1024 different subsets" : "wrong (" + to_string(got.size()) + " subsets)"),
          string("1024 different subsets"));

    cout << passed << "/" << total << " tests passed\n";
}
