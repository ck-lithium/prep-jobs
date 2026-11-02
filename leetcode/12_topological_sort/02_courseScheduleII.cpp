/*
 * Course Schedule II
 * LeetCode 210 (Medium) - https://leetcode.com/problems/course-schedule-ii/
 *
 * There are `numCourses` courses, numbered 0 to numCourses - 1.
 * prerequisites[i] = [a, b] means you must take course b before course a.
 *
 * Return an order in which you can take all the courses. If several orders
 * work, return any of them. If it's impossible, return an empty array.
 *
 * This is the follow-up to Course Schedule (problem 12 of the initial set):
 * now you return the order itself.
 *
 * Example 1:
 *   Input:  numCourses = 2, prerequisites = [[1, 0]]
 *   Output: [0, 1]
 *
 * Example 2:
 *   Input:  numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
 *   Output: [0, 1, 2, 3]    ([0, 2, 1, 3] is also correct)
 *
 * Example 3:
 *   Input:  numCourses = 1, prerequisites = []
 *   Output: [0]
 *
 * Constraints:
 *   1 <= numCourses <= 2000
 *   0 <= prerequisites.length <= numCourses * (numCourses - 1)
 *   All pairs are different, and a != b.
 *
 * Target: O(V + E) with Kahn's algorithm: repeatedly take a course whose
 * prerequisites are all done (in-degree 0).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_courseScheduleII.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
string str(const string& s) { return s; }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

// Many orders can be correct, so the tests check the order instead of
// comparing it with one fixed answer.
string verdict(const vector<int>& order, int n, const vector<vector<int>>& prerequisites) {
    if (order.empty()) return "[]";
    if ((int)order.size() != n) return "invalid order " + str(order);
    vector<int> position(n, -1);
    for (int i = 0; i < n; i++) {
        if (order[i] < 0 || order[i] >= n || position[order[i]] != -1) return "invalid order " + str(order);
        position[order[i]] = i;
    }
    for (auto& p : prerequisites)
        if (position[p[1]] > position[p[0]]) return "invalid order " + str(order);
    return "a valid order";
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

    struct Case { int numCourses; vector<vector<int>> prerequisites; bool possible; };
    vector<Case> cases = {
        {2, {{1, 0}}, true},
        {4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, true},
        {1, {}, true},
        {2, {{1, 0}, {0, 1}}, false},
        {3, {}, true},
        {3, {{0, 1}, {1, 2}}, true},
        {5, {{1, 0}, {3, 2}, {4, 3}, {2, 4}}, false},   // 2 -> 3 -> 4 -> 2 is a cycle
        {6, {{5, 4}, {4, 3}, {3, 2}, {2, 1}, {1, 0}, {5, 0}}, true},
    };
    for (auto& c : cases) {
        auto order = sol.findOrder(c.numCourses, c.prerequisites);
        check(verdict(order, c.numCourses, c.prerequisites), string(c.possible ? "a valid order" : "[]"));
    }

    // Big input: 2000 courses in a chain: course i + 1 needs course i.
    vector<vector<int>> chain;
    for (int i = 0; i + 1 < 2000; i++) chain.push_back({i + 1, i});
    check(verdict(sol.findOrder(2000, chain), 2000, chain), string("a valid order"));

    cout << passed << "/" << total << " tests passed\n";
}
