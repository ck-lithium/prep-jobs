/*
 * Network Delay Time
 * LeetCode 743 (Medium) - https://leetcode.com/problems/network-delay-time/
 *
 * A network has n nodes, labelled 1 to n. times[i] = [u, v, w] means a signal
 * sent from u reaches v after w time units (the edges are one-way).
 *
 * A signal starts at node k. Return how long it takes until every node has
 * received it, or -1 if some node never does.
 *
 * Example 1:
 *   Input:  times = [[2, 1, 1], [2, 3, 1], [3, 4, 1]], n = 4, k = 2
 *   Output: 2
 *   Why:    node 4 is the last, reached through 3 at time 2.
 *
 * Example 2:
 *   Input:  times = [[1, 2, 1]], n = 2, k = 1
 *   Output: 1
 *
 * Example 3:
 *   Input:  times = [[1, 2, 1]], n = 2, k = 2
 *   Output: -1
 *   Why:    the only edge goes from 1 to 2, so node 1 is never reached.
 *
 * Constraints:
 *   1 <= k <= n <= 100
 *   1 <= times.length <= 6000
 *   0 <= w <= 100, u != v, and no (u, v) pair appears twice.
 *
 * Target: O(E log V) with Dijkstra's algorithm: a min-heap of (time, node),
 * always settling the closest unsettled node next. The answer is the largest
 * of the shortest times.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_networkDelayTime.cpp && ./a.out
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

    struct Case { vector<vector<int>> times; int n, k; int expected; };
    vector<Case> cases = {
        {{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2, 2},
        {{{1, 2, 1}}, 2, 1, 1},
        {{{1, 2, 1}}, 2, 2, -1},
        {{{1, 2, 1}, {2, 3, 2}, {1, 3, 4}}, 3, 1, 3},   // the detour is faster
        {{{1, 2, 1}, {2, 1, 3}}, 2, 2, 3},
        {{{1, 2, 0}, {2, 3, 0}}, 3, 1, 0},
        {{{1, 2, 5}, {1, 3, 1}, {3, 2, 1}}, 3, 1, 2},
    };
    for (auto& c : cases) check(sol.networkDelayTime(c.times, c.n, c.k), c.expected);

    // Bigger input: 100 nodes, with an edge both ways between any two nodes at
    // most 30 apart (5070 edges). A jump of d costs d * d, so stepping one node
    // at a time is cheapest: node v is reached at time v - 1, and the last one
    // at 99. Fewest hops (plain BFS) would take the expensive long jumps.
    vector<vector<int>> dense;
    for (int u = 1; u <= 100; u++)
        for (int v = 1; v <= 100; v++)
            if (u != v && abs(u - v) <= 30) dense.push_back({u, v, (u - v) * (u - v)});
    check(sol.networkDelayTime(dense, 100, 1), 99);

    cout << passed << "/" << total << " tests passed\n";
}
