/*
 * Find if Path Exists in Graph
 * LeetCode 1971 (Easy) - https://leetcode.com/problems/find-if-path-exists-in-graph/
 *
 * A graph has `n` vertices, numbered 0 to n - 1. Each edges[i] = [u, v] is an
 * undirected edge between u and v. Return true if there is a path from
 * `source` to `destination`.
 *
 * Example 1:
 *   Input:  n = 3, edges = [[0, 1], [1, 2], [2, 0]], source = 0, destination = 2
 *   Output: true
 *
 * Example 2:
 *   Input:  n = 6, edges = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]],
 *           source = 0, destination = 5
 *   Output: false
 *   Why:    {0, 1, 2} and {3, 4, 5} are separate pieces.
 *
 * Constraints:
 *   1 <= n <= 2 * 10^5
 *   0 <= edges.length <= 2 * 10^5
 *   No duplicate edges and no self-loops.
 *
 * Target: O(n + edges). Build an adjacency list, then search from `source`.
 * The last test is a single chain of 2 * 10^5 vertices, so a recursive DFS
 * goes 2 * 10^5 calls deep: built with -O2 it just fits in Linux's default
 * 8 MB stack, but built with -O0 it crashes. For deep graphs, an explicit
 * stack or a queue is safer (union-find works too).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_findIfPathExists.cpp && ./a.out
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

    struct Case { int n; vector<vector<int>> edges; int source, destination; bool expected; };
    vector<Case> cases = {
        {3, {{0, 1}, {1, 2}, {2, 0}}, 0, 2, true},
        {6, {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 0, 5, false},
        {1, {}, 0, 0, true},
        {2, {}, 0, 1, false},
        {4, {{0, 1}, {2, 3}}, 1, 0, true},
        {4, {{0, 1}, {2, 3}}, 0, 3, false},
        {5, {{0, 4}, {4, 3}, {3, 2}, {2, 1}}, 1, 0, true},
    };
    for (auto& c : cases) check(sol.validPath(c.n, c.edges, c.source, c.destination), c.expected);

    // Big input: a chain 0 - 1 - 2 - ... - 199999.
    vector<vector<int>> chain;
    for (int i = 0; i + 1 < 200000; i++) chain.push_back({i, i + 1});
    check(sol.validPath(200000, chain, 0, 199999), true);

    cout << passed << "/" << total << " tests passed\n";
}
