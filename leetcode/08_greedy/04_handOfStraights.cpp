/*
 * Hand of Straights
 * LeetCode 846 (Medium) - https://leetcode.com/problems/hand-of-straights/
 *
 * You hold cards with the numbers in `hand`. Return true if you can split all
 * of them into groups of exactly `groupSize` cards, where each group is a run
 * of consecutive numbers, like 3, 4, 5.
 *
 * Example 1:
 *   Input:  hand = [1, 2, 3, 6, 2, 3, 4, 7, 8], groupSize = 3
 *   Output: true
 *   Why:    [1, 2, 3], [2, 3, 4], [6, 7, 8].
 *
 * Example 2:
 *   Input:  hand = [1, 2, 3, 4, 5], groupSize = 4
 *   Output: false
 *   Why:    5 cards can't be split into groups of 4.
 *
 * Constraints:
 *   1 <= hand.length <= 10^4
 *   0 <= hand[i] <= 10^9
 *   1 <= groupSize <= hand.length
 *
 * Target: O(n log n). The smallest card left must start a group: there's no
 * smaller card it could follow.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_handOfStraights.cpp && ./a.out
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

    struct Case { vector<int> hand; int groupSize; bool expected; };
    vector<Case> cases = {
        {{1, 2, 3, 6, 2, 3, 4, 7, 8}, 3, true},
        {{1, 2, 3, 4, 5}, 4, false},
        {{1}, 1, true},
        {{1, 2, 3}, 1, true},
        {{1, 1, 2, 2, 3, 3}, 3, true},
        {{1, 1, 2, 2, 3, 4}, 3, false},
        {{8, 10, 12}, 3, false},
        {{1000000000, 999999999, 999999998}, 3, true},
        {{1, 2, 3, 4, 5, 6}, 2, true},
        {{2, 1}, 2, true},
    };
    for (auto& c : cases) check(sol.isNStraightHand(c.hand, c.groupSize), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
