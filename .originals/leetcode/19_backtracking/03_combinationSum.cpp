/*
 * Combination Sum
 * LeetCode 39 (Medium) - https://leetcode.com/problems/combination-sum/
 *
 * Given an array of distinct integers `candidates` and a `target`, return all
 * the different combinations of candidates that add up to `target`. Each
 * candidate can be used any number of times. Two combinations are different
 * if some number is used a different number of times, so [2, 2, 3] and
 * [3, 2, 2] are the same combination. Return them in any order.
 *
 * Example 1:
 *   Input:  candidates = [2, 3, 6, 7], target = 7
 *   Output: [[2, 2, 3], [7]]
 *
 * Example 2:
 *   Input:  candidates = [2, 3, 5], target = 8
 *   Output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
 *
 * Example 3:
 *   Input:  candidates = [2], target = 1
 *   Output: []
 *
 * Constraints:
 *   1 <= candidates.length <= 30
 *   2 <= candidates[i] <= 40, all different
 *   1 <= target <= 40
 *
 * Target: backtracking that never produces the same combination twice. Pass
 * down a start index, and only pick candidates from that index onwards (the
 * current one included, since it can repeat).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_combinationSum.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

// Any order is accepted, so sort inside each combination and then sort the list.
vector<vector<int>> normalize(vector<vector<int>> combos) {
    for (auto& c : combos) sort(c.begin(), c.end());
    sort(combos.begin(), combos.end());
    return combos;
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

    struct Case { vector<int> candidates; int target; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{2, 3, 6, 7}, 7, {{2, 2, 3}, {7}}},
        {{2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}},
        {{2}, 1, {}},
        {{8, 7, 4, 3}, 11, {{3, 4, 4}, {3, 8}, {4, 7}}},
        {{2, 4}, 7, {}},
        {{5, 10}, 15, {{5, 5, 5}, {5, 10}}},
        {{2}, 2, {{2}}},
    };
    for (auto& c : cases) check(normalize(sol.combinationSum(c.candidates, c.target)), normalize(c.expected));

    cout << passed << "/" << total << " tests passed\n";
}
