/*
 * Car Pooling
 * LeetCode 1094 (Medium) - https://leetcode.com/problems/car-pooling/
 *
 * A car with `capacity` empty seats drives east along a road and never turns
 * back. trips[i] = [numPassengers, from, to] means numPassengers people get in
 * at kilometre `from` and get out at kilometre `to`.
 *
 * Return true if the car can complete every trip without ever carrying more
 * than `capacity` passengers. People who get out at kilometre x free their
 * seats before anyone gets in at x.
 *
 * Example 1:
 *   Input:  trips = [[2, 1, 5], [3, 3, 7]], capacity = 4
 *   Output: false
 *   Why:    between km 3 and 5 there are 2 + 3 = 5 passengers.
 *
 * Example 2:
 *   Input:  trips = [[2, 1, 5], [3, 3, 7]], capacity = 5
 *   Output: true
 *
 * Constraints:
 *   1 <= trips.length <= 1000
 *   1 <= numPassengers <= 100
 *   0 <= from < to <= 1000
 *   1 <= capacity <= 10^5
 *
 * Target: O(n + max km) with a "difference array": +passengers at `from`,
 * -passengers at `to`, then a running sum along the road. (Sorting the pick-up
 * and drop-off events also works.)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_carPooling.cpp && ./a.out
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

    struct Case { vector<vector<int>> trips; int capacity; bool expected; };
    vector<Case> cases = {
        {{{2, 1, 5}, {3, 3, 7}}, 4, false},
        {{{2, 1, 5}, {3, 3, 7}}, 5, true},
        {{{2, 1, 5}, {3, 5, 7}}, 3, true},    // drop-off at 5 before pick-up at 5
        {{{3, 2, 7}, {3, 7, 9}, {8, 3, 9}}, 11, true},
        {{{9, 0, 1}, {3, 3, 7}}, 4, false},
        {{{1, 0, 1000}}, 1, true},
        {{{5, 0, 3}, {5, 1, 2}, {1, 2, 4}}, 10, true},
        {{{5, 0, 3}, {5, 1, 2}, {1, 2, 4}}, 9, false},
    };
    for (auto& c : cases) check(sol.carPooling(c.trips, c.capacity), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
