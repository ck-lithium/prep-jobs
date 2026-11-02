/*
 * Gas Station
 * LeetCode 134 (Medium) - https://leetcode.com/problems/gas-station/
 *
 * There are n gas stations on a circular route. Station i has gas[i] units of
 * fuel, and driving from station i to station i + 1 (or from the last one back
 * to station 0) burns cost[i] units.
 *
 * Your car has an unlimited tank and starts empty at one of the stations. At
 * each station you fill up with all of its gas. Return the index of the
 * station to start from so you can drive around the whole circle once, or -1
 * if no start works. The tests guarantee the answer is unique.
 *
 * Example 1:
 *   Input:  gas = [1, 2, 3, 4, 5], cost = [3, 4, 5, 1, 2]
 *   Output: 3
 *   Why:    start at 3 with 4 units: 4-1+5 = 8, 8-2+1 = 7, 7-3+2 = 6,
 *           6-4+3 = 5, and 5-5 = 0 is just enough to get back to 3.
 *
 * Example 2:
 *   Input:  gas = [2, 3, 4], cost = [3, 4, 3]
 *   Output: -1
 *
 * Constraints:
 *   1 <= n <= 10^5
 *   0 <= gas[i], cost[i] <= 10^4
 *
 * Target: O(n), one pass. Two facts do the work: if the total gas is less than
 * the total cost, no start works; and if you run dry between stations a and b,
 * no station between a and b can be the start either.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_gasStation.cpp && ./a.out
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

    struct Case { vector<int> gas, cost; int expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3},
        {{2, 3, 4}, {3, 4, 3}, -1},
        {{5}, {4}, 0},
        {{1}, {2}, -1},
        {{3, 1, 1}, {1, 2, 2}, 0},
        {{5, 1, 2, 3, 4}, {4, 4, 1, 5, 1}, 4},
        {{4, 0, 0}, {1, 1, 3}, -1},
    };
    for (auto& c : cases) check(sol.canCompleteCircuit(c.gas, c.cost), c.expected);

    // Big input: 10^5 stations with 1 gas and cost 1, except station 50000 has
    // 2 gas and the trip out of station 49999 costs 2. Only 50000 works.
    // Trying every start (O(n^2)) is far too slow here.
    vector<int> gas(100000, 1), cost(100000, 1);
    gas[50000] = 2;
    cost[49999] = 2;
    check(sol.canCompleteCircuit(gas, cost), 50000);

    cout << passed << "/" << total << " tests passed\n";
}
