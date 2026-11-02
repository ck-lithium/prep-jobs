/*
 * Course Schedule IV
 * LeetCode 1462 (Medium) - https://leetcode.com/problems/course-schedule-iv/
 *
 * There are `numCourses` courses, numbered 0 to numCourses - 1.
 * prerequisites[i] = [a, b] means course a must be taken before course b.
 * (Careful: that's the opposite order from Course Schedule I and II.)
 *
 * Prerequisites can be indirect: if a comes before b and b before c, then a is
 * a prerequisite of c.
 *
 * For each query [u, v], answer whether u is a prerequisite of v, directly or
 * indirectly.
 *
 * Example 1:
 *   Input:  numCourses = 2, prerequisites = [[1, 0]], queries = [[0, 1], [1, 0]]
 *   Output: [false, true]
 *
 * Example 2:
 *   Input:  numCourses = 2, prerequisites = [], queries = [[1, 0], [0, 1]]
 *   Output: [false, false]
 *
 * Example 3:
 *   Input:  numCourses = 3, prerequisites = [[1, 2], [1, 0], [2, 0]],
 *           queries = [[1, 0], [1, 2]]
 *   Output: [true, true]
 *
 * Constraints:
 *   2 <= numCourses <= 100
 *   0 <= prerequisites.length <= numCourses * (numCourses - 1) / 2
 *   The prerequisites have no cycles.
 *   1 <= queries.length <= 10^4, and u != v in every query.
 *
 * Target: precompute, then answer each query in O(1). With at most 100
 * courses you can afford an n x n "is a prerequisite of" table, filled in
 * topological order (or with Floyd-Warshall-style transitive closure).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_courseScheduleIV.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str((bool)v[i]);
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

    struct Case { int n; vector<vector<int>> prerequisites, queries; vector<bool> expected; };
    vector<Case> cases = {
        {2, {{1, 0}}, {{0, 1}, {1, 0}}, {false, true}},
        {2, {}, {{1, 0}, {0, 1}}, {false, false}},
        {3, {{1, 2}, {1, 0}, {2, 0}}, {{1, 0}, {1, 2}}, {true, true}},
        {4, {{0, 1}, {1, 2}, {2, 3}}, {{0, 3}, {3, 0}, {1, 3}, {2, 1}}, {true, false, true, false}},
        {5, {{0, 1}, {2, 3}}, {{0, 3}, {2, 3}, {1, 0}}, {false, true, false}},
        {5, {{0, 1}, {1, 2}, {3, 2}, {2, 4}}, {{3, 4}, {0, 4}, {4, 0}, {0, 3}}, {true, true, false, false}},
    };
    for (auto& c : cases) check(sol.checkIfPrerequisite(c.n, c.prerequisites, c.queries), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
