/*
 * Find the Town Judge
 * LeetCode 997 (Easy) - https://leetcode.com/problems/find-the-town-judge/
 *
 * A town has n people, labelled 1 to n. Rumour says one of them is secretly
 * the town judge. If the judge exists:
 *   1. the judge trusts nobody;
 *   2. everybody else trusts the judge;
 *   3. exactly one person satisfies 1 and 2.
 *
 * trust[i] = [a, b] means person a trusts person b. Return the judge's label,
 * or -1 if there is no judge.
 *
 * Example 1:
 *   Input:  n = 2, trust = [[1, 2]]
 *   Output: 2
 *
 * Example 2:
 *   Input:  n = 3, trust = [[1, 3], [2, 3]]
 *   Output: 3
 *
 * Example 3:
 *   Input:  n = 3, trust = [[1, 3], [2, 3], [3, 1]]
 *   Output: -1
 *   Why:    3 trusts 1, so 3 can't be the judge.
 *
 * Constraints:
 *   1 <= n <= 1000
 *   0 <= trust.length <= 10^4
 *   All pairs are different, and a != b.
 *
 * Target: O(n + trust.length). Count each person's in-degree (how many trust
 * them) and out-degree (how many they trust). Degree counting is the first
 * step of Kahn's topological sort.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_findTheTownJudge.cpp && ./a.out
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

    struct Case { int n; vector<vector<int>> trust; int expected; };
    vector<Case> cases = {
        {2, {{1, 2}}, 2},
        {3, {{1, 3}, {2, 3}}, 3},
        {3, {{1, 3}, {2, 3}, {3, 1}}, -1},
        {1, {}, 1},                       // a town of one: they trust nobody, and nobody else exists
        {2, {}, -1},
        {4, {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}}, 3},
        {3, {{1, 2}, {2, 3}}, -1},
    };
    for (auto& c : cases) check(sol.findJudge(c.n, c.trust), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
