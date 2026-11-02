/*
 * Cheapest Flights Within K Stops
 * LeetCode 787 (Medium) - https://leetcode.com/problems/cheapest-flights-within-k-stops/
 *
 * There are n cities, numbered 0 to n - 1. flights[i] = [from, to, price] is a
 * one-way flight. Return the cheapest price from `src` to `dst` using at most
 * `k` stops in between (so at most k + 1 flights), or -1 if there is no such
 * route.
 *
 * Example 1:
 *   Input:  n = 4, flights = [[0, 1, 100], [1, 2, 100], [2, 0, 100],
 *                              [1, 3, 600], [2, 3, 200]],
 *           src = 0, dst = 3, k = 1
 *   Output: 700
 *   Why:    0 -> 1 -> 3 costs 700. 0 -> 1 -> 2 -> 3 costs only 400 but needs
 *           2 stops.
 *
 * Example 2:
 *   Input:  n = 3, flights = [[0, 1, 100], [1, 2, 100], [0, 2, 500]],
 *           src = 0, dst = 2, k = 1
 *   Output: 200
 *
 * Example 3:
 *   Input:  the same flights, k = 0
 *   Output: 500
 *
 * Constraints:
 *   1 <= n <= 100
 *   0 <= flights.length <= n * (n - 1) / 2
 *   1 <= price <= 10^4, and no two flights share the same from and to.
 *   0 <= src, dst, k < n, and src != dst.
 *
 * Target: O(k * flights) with Bellman-Ford limited to k + 1 rounds: each round
 * allows one more flight. Copy the prices at the start of each round, or one
 * round can chain several flights. Plain Dijkstra on price alone is wrong
 * here: the cheapest way into a city may use too many stops.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_cheapestFlightsWithinKStops.cpp && ./a.out
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

    vector<vector<int>> ex1 = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    vector<vector<int>> ex2 = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    vector<vector<int>> ladder = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    struct Case { int n; vector<vector<int>> flights; int src, dst, k; int expected; };
    vector<Case> cases = {
        {4, ex1, 0, 3, 1, 700},
        {3, ex2, 0, 2, 1, 200},
        {3, ex2, 0, 2, 0, 500},
        {2, {}, 0, 1, 0, -1},
        {3, {{0, 1, 1}, {1, 2, 1}}, 0, 2, 0, -1},   // the only route needs a stop
        {4, ladder, 0, 3, 1, 6},                     // 0 -> 2 -> 3
        {4, ladder, 0, 3, 2, 3},                     // 0 -> 1 -> 2 -> 3
        {4, ex1, 0, 3, 2, 400},
    };
    for (auto& c : cases) check(sol.findCheapestPrice(c.n, c.flights, c.src, c.dst, c.k), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
