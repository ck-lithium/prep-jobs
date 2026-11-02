/*
 * Meeting Rooms III
 * LeetCode 2402 (Hard) - https://leetcode.com/problems/meeting-rooms-iii/
 *
 * There are `n` rooms, numbered 0 to n - 1. meetings[i] = [start, end] is a
 * meeting that wants the time span from `start` up to, but not including,
 * `end`. All start times are different.
 *
 * Meetings are given rooms like this, in order of their start time:
 *   1. A meeting goes to the free room with the lowest number.
 *   2. If no room is free, the meeting waits until a room frees up, and then
 *      takes it, keeping its original length. If several rooms free up at the
 *      same moment, it takes the lowest-numbered one.
 *   3. When several meetings are waiting, the one with the earlier original
 *      start time goes first.
 *
 * Return the number of the room that held the most meetings. On a tie, return
 * the lowest room number.
 *
 * Example 1:
 *   Input:  n = 2, meetings = [[0, 10], [1, 5], [2, 7], [3, 4]]
 *   Output: 0
 *   Why:    [0,10] -> room 0, [1,5] -> room 1. [2,7] waits for room 1 and runs
 *           5..10. [3,4] waits, and at time 10 both rooms are free: it takes
 *           room 0 and runs 10..11. Rooms 0 and 1 both held 2 meetings.
 *
 * Example 2:
 *   Input:  n = 3, meetings = [[1, 20], [2, 10], [3, 5], [4, 9], [6, 8]]
 *   Output: 1
 *
 * Constraints:
 *   1 <= n <= 100
 *   1 <= meetings.length <= 10^5
 *   0 <= start < end <= 5 * 10^5
 *   All start times are different.
 *
 * Target: O(m log m + m log n) with two min-heaps: free room numbers, and busy
 * rooms ordered by (time they become free, room number). Delayed meetings can
 * end far later than 5 * 10^5, beyond what an int can hold.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_meetingRoomsIII.cpp && ./a.out
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

    struct Case { int n; vector<vector<int>> meetings; int expected; };
    vector<Case> cases = {
        {2, {{0, 10}, {1, 5}, {2, 7}, {3, 4}}, 0},
        {3, {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}}, 1},
        {1, {{0, 1}}, 0},
        {4, {{18, 19}, {3, 12}, {17, 19}, {2, 13}, {7, 10}}, 0},
        {2, {{0, 10}, {1, 5}, {6, 8}, {9, 11}}, 1},
        {3, {{0, 5}, {1, 2}, {2, 3}, {3, 4}, {4, 9}}, 1},
    };
    for (auto& c : cases) check(sol.mostBooked(c.n, c.meetings), c.expected);

    // Big input: 10^5 long meetings in 3 rooms. Most of them get delayed, and
    // the end times climb past 10^10, so they need a 64-bit type.
    vector<vector<int>> big;
    for (int i = 0; i < 100000; i++) big.push_back({i, i + 400000 + (i * 37) % 100000});
    check(sol.mostBooked(3, big), 2);  // room 2 holds 33334 meetings, the others 33333

    cout << passed << "/" << total << " tests passed\n";
}
