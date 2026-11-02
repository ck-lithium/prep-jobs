/*
 * Redundant Connection
 * LeetCode 684 (Medium) - https://leetcode.com/problems/redundant-connection/
 *
 * A tree with n nodes (labelled 1 to n) got one extra edge, which created a
 * cycle. You get the n edges, each [a, b] an undirected edge. Return an edge
 * whose removal turns the graph back into a tree. If several edges would
 * work, return the one that appears last in the input.
 *
 * Example 1:
 *   Input:  edges = [[1, 2], [1, 3], [2, 3]]
 *   Output: [2, 3]
 *
 * Example 2:
 *   Input:  edges = [[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]
 *   Output: [1, 4]
 *   Why:    the cycle is 1-2-3-4-1; of its edges, [1, 4] comes last.
 *
 * Constraints:
 *   3 <= n <= 1000, and edges.length == n
 *   1 <= a < b <= n, no repeated edges, and the graph is connected.
 *
 * Target: about O(n) with union-find (disjoint sets). Add the edges one by
 * one; the first edge whose two ends are already in the same set closes the
 * cycle. Use path compression and union by size or rank.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_redundantConnection.cpp && ./a.out
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

    struct Case { vector<vector<int>> edges; vector<int> expected; };
    vector<Case> cases = {
        {{{1, 2}, {1, 3}, {2, 3}}, {2, 3}},
        {{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}}, {1, 4}},
        {{{1, 2}, {2, 3}, {1, 3}}, {1, 3}},
        {{{1, 4}, {3, 4}, {1, 3}, {1, 2}, {4, 5}}, {1, 3}},
        {{{3, 4}, {1, 2}, {2, 4}, {3, 5}, {2, 5}}, {2, 5}},
    };
    for (auto& c : cases) check(sol.findRedundantConnection(c.edges), c.expected);

    // Big input: the chain 1-2-...-1000 plus the edge [1, 1000].
    vector<vector<int>> chain;
    for (int i = 1; i < 1000; i++) chain.push_back({i, i + 1});
    chain.push_back({1, 1000});
    check(sol.findRedundantConnection(chain), vector<int>{1, 1000});

    cout << passed << "/" << total << " tests passed\n";
}
