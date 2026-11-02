/*
 * Find Eventual Safe States
 * LeetCode 802 (Medium) - https://leetcode.com/problems/find-eventual-safe-states/
 *
 * A directed graph has n nodes, numbered 0 to n - 1. graph[i] lists the nodes
 * that node i has edges to.
 *
 * A node with no outgoing edges is a "terminal" node. A node is "safe" if
 * every path starting from it ends at a terminal node: no path from it can
 * run into a cycle.
 *
 * Return all the safe nodes, sorted in ascending order.
 *
 * Example 1:
 *   Input:  graph = [[1, 2], [2, 3], [5], [0], [5], [], []]
 *   Output: [2, 4, 5, 6]
 *   Why:    0 -> 1 -> 3 -> 0 is a cycle, so 0, 1 and 3 are not safe.
 *
 * Example 2:
 *   Input:  graph = [[1, 2, 3, 4], [1, 2], [3, 4], [0, 4], []]
 *   Output: [4]
 *
 * Constraints:
 *   1 <= n <= 10^4
 *   0 <= total number of edges <= 4 * 10^4
 *   graph[i] is sorted and has no duplicates. It may contain i itself (a
 *   self-loop).
 *
 * Target: O(V + E). Reverse every edge, then run Kahn's algorithm from the
 * terminal nodes: a node becomes safe once all the nodes it points to are safe.
 * (A DFS that colours nodes "in progress" / "done" also works.)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_findEventualSafeStates.cpp && ./a.out
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

    struct Case { vector<vector<int>> graph; vector<int> expected; };
    vector<Case> cases = {
        {{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}}, {2, 4, 5, 6}},
        {{{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}}, {4}},
        {{{}}, {0}},
        {{{0}}, {}},                    // a self-loop is a cycle
        {{{1}, {}}, {0, 1}},
        {{{1}, {0}}, {}},
        {{{1}, {2}, {}}, {0, 1, 2}},
        {{{1}, {1, 2}, {}}, {2}},
    };
    for (auto& c : cases) check(sol.eventualSafeNodes(c.graph), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
