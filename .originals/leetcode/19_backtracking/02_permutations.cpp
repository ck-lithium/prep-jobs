/*
 * Permutations
 * LeetCode 46 (Medium) - https://leetcode.com/problems/permutations/
 *
 * Given an array of distinct integers, return every possible ordering
 * (permutation) of its elements, in any order.
 *
 * Example 1:
 *   Input:  nums = [1, 2, 3]
 *   Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
 *
 * Example 2:
 *   Input:  nums = [0, 1]
 *   Output: [[0, 1], [1, 0]]
 *
 * Example 3:
 *   Input:  nums = [1]
 *   Output: [[1]]
 *
 * Constraints:
 *   1 <= nums.length <= 6
 *   -10 <= nums[i] <= 10
 *   All values are different.
 *
 * Target: O(n * n!), the size of the answer. Build each permutation one
 * position at a time, trying every element not used yet. Don't use
 * std::next_permutation: the point is to write the backtracking yourself.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_permutations.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
string str(const string& s) { return s; }
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

    struct Case { vector<int> nums; vector<vector<int>> expected; };  // expected is sorted
    vector<Case> cases = {
        {{1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}},
        {{0, 1}, {{0, 1}, {1, 0}}},
        {{1}, {{1}}},
        {{-5, 5}, {{-5, 5}, {5, -5}}},
    };
    for (auto& c : cases) {
        // Any order is accepted, so sort the list (but not inside each one).
        auto got = sol.permute(c.nums);
        sort(got.begin(), got.end());
        check(got, c.expected);
    }

    // Six numbers: there must be 6! = 720 different orderings of them.
    vector<int> six = {4, -2, 9, 0, 7, -10};
    auto got = sol.permute(six);
    sort(got.begin(), got.end());
    vector<int> sortedSix = six;
    sort(sortedSix.begin(), sortedSix.end());
    bool ok = got.size() == 720 && adjacent_find(got.begin(), got.end()) == got.end();
    for (auto p : got) {
        sort(p.begin(), p.end());
        ok &= p == sortedSix;
    }
    check(string(ok ? "720 different permutations" : "wrong (" + to_string(got.size()) + " results)"),
          string("720 different permutations"));

    cout << passed << "/" << total << " tests passed\n";
}
