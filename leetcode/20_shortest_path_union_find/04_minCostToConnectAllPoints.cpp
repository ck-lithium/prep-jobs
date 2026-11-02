/*
 * Min Cost to Connect All Points
 * LeetCode 1584 (Medium) - https://leetcode.com/problems/min-cost-to-connect-all-points/
 *
 * You are given points on a plane, points[i] = [x, y]. Connecting two points
 * costs their Manhattan distance |x1 - x2| + |y1 - y2|. Return the minimum
 * total cost to connect all the points, so that there is exactly one path
 * between any two of them.
 *
 * In other words: the weight of a minimum spanning tree (MST) of the complete
 * graph on the points.
 *
 * Example 1:
 *   Input:  points = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
 *   Output: 20
 *
 * Example 2:
 *   Input:  points = [[3, 12], [-2, 5], [-4, 1]]
 *   Output: 18
 *
 * Constraints:
 *   1 <= points.length <= 1000
 *   -10^6 <= x, y <= 10^6
 *   All points are different.
 *
 * Target: Prim's algorithm in O(n^2) (best for a complete graph), or
 * Kruskal's: sort all n(n - 1)/2 edges and add them with union-find, skipping
 * edges that would close a cycle.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_minCostToConnectAllPoints.cpp && ./a.out
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

    struct Case { vector<vector<int>> points; int expected; };
    vector<Case> cases = {
        {{{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}}, 20},
        {{{3, 12}, {-2, 5}, {-4, 1}}, 18},
        {{{0, 0}}, 0},
        {{{0, 0}, {1, 1}}, 2},
        {{{0, 0}, {1, 0}, {2, 0}, {3, 0}}, 3},
        {{{-1000000, -1000000}, {1000000, 1000000}}, 4000000},
    };
    for (auto& c : cases) check(sol.minCostConnectPoints(c.points), c.expected);

    // Big input: 1000 points on a line, one unit apart.
    vector<vector<int>> line;
    for (int i = 0; i < 1000; i++) line.push_back({i, 0});
    check(sol.minCostConnectPoints(line), 999);

    cout << passed << "/" << total << " tests passed\n";
}
