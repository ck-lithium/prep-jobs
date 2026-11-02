/*
 * 12 - TOPOLOGICAL SORT: Course Schedule
 * LeetCode 207 (Medium) - https://leetcode.com/problems/course-schedule/
 *
 * There are `numCourses` courses, numbered 0 to numCourses - 1. You are given
 * an array `prerequisites` where prerequisites[i] = [a, b] means you must take
 * course b before you can take course a.
 *
 * Return true if it is possible to finish every course, false otherwise.
 *
 * Example 1:
 *   Input:  numCourses = 2, prerequisites = [[1, 0]]
 *   Output: true
 *   Why:    take course 0, then course 1.
 *
 * Example 2:
 *   Input:  numCourses = 2, prerequisites = [[1, 0], [0, 1]]
 *   Output: false
 *   Why:    each course needs the other one first.
 *
 * Constraints:
 *   1 <= numCourses <= 2000
 *   0 <= prerequisites.length <= 5000
 *   prerequisites[i].length == 2
 *   0 <= a, b < numCourses
 *   All pairs in prerequisites are different.
 *
 * Target: O(V + E) time, where V = numCourses and E = prerequisites.length.
 *
 * Follow-up: LeetCode 210 (Course Schedule II) asks you to return a valid order.
 *
 * How to spot this pattern: dependencies, prerequisites, build order, "X must
 * happen before Y", or "detect a cycle in a directed graph".
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 12_topologicalSort_courseSchedule.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { int numCourses; vector<vector<int>> prerequisites; bool expected; };
    vector<Case> cases = {
        {2, {{1, 0}}, true},
        {2, {{1, 0}, {0, 1}}, false},
        {4, {{1, 0}, {2, 1}, {3, 2}}, true},
        {3, {{0, 1}, {1, 2}, {2, 0}}, false},
        {5, {}, true},
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, true},
        {6, {{1, 0}, {3, 2}, {4, 3}, {2, 4}}, false},  // the cycle is not reachable from course 0
    };
    for (auto& c : cases) check(sol.canFinish(c.numCourses, c.prerequisites), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
