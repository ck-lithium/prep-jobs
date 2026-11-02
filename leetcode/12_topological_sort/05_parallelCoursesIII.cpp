/*
 * Parallel Courses III
 * LeetCode 2050 (Hard) - https://leetcode.com/problems/parallel-courses-iii/
 *
 * There are n courses, labelled 1 to n. relations[j] = [prev, next] means
 * course `prev` must be finished before course `next` can start. Course i
 * takes time[i - 1] months.
 *
 * You can take any number of courses at the same time, and start a course as
 * soon as all its prerequisites are finished. Return the minimum number of
 * months needed to finish every course. The relations never form a cycle.
 *
 * Example 1:
 *   Input:  n = 3, relations = [[1, 3], [2, 3]], time = [3, 2, 5]
 *   Output: 8
 *   Why:    courses 1 and 2 start at month 0; course 3 starts when course 1
 *           ends at month 3 and finishes at 3 + 5 = 8.
 *
 * Example 2:
 *   Input:  n = 5, relations = [[1, 5], [2, 5], [3, 5], [3, 4], [4, 5]],
 *           time = [1, 2, 3, 4, 5]
 *   Output: 12
 *   Why:    3 -> 4 -> 5 takes 3 + 4 + 5 months.
 *
 * Constraints:
 *   1 <= n <= 5 * 10^4
 *   0 <= relations.length <= min(n * (n + 1) / 2, 5 * 10^4)
 *   1 <= prev, next <= n, prev != next, and all pairs are different.
 *   The relations form no cycle.
 *   1 <= time[i] <= 10^4
 *
 * Target: O(n + relations). Process courses in topological order: a course
 * finishes at (latest finish among its prerequisites) + its own time. The
 * answer is the longest path through the dependency graph, weighted by time.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_parallelCoursesIII.cpp && ./a.out
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

    struct Case { int n; vector<vector<int>> relations; vector<int> time; int expected; };
    vector<Case> cases = {
        {3, {{1, 3}, {2, 3}}, {3, 2, 5}, 8},
        {5, {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}}, {1, 2, 3, 4, 5}, 12},
        {1, {}, {7}, 7},
        {3, {}, {1, 5, 3}, 5},
        {3, {{1, 2}, {2, 3}}, {1, 2, 3}, 6},
        {4, {{1, 2}, {1, 3}, {2, 4}, {3, 4}}, {2, 3, 7, 1}, 10},
    };
    for (auto& c : cases) check(sol.minimumTime(c.n, c.relations, c.time), c.expected);

    // Big input: a chain of 50000 courses of 10^4 months each.
    vector<vector<int>> chain;
    for (int i = 1; i < 50000; i++) chain.push_back({i, i + 1});
    vector<int> time(50000, 10000);
    check(sol.minimumTime(50000, chain, time), 500000000);

    cout << passed << "/" << total << " tests passed\n";
}
