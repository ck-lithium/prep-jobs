/*
 * Last Stone Weight
 * LeetCode 1046 (Easy) - https://leetcode.com/problems/last-stone-weight/
 *
 * You have stones with the given weights. On each turn, take the two heaviest
 * stones, x and y with x <= y, and smash them together:
 *   - if x == y, both are destroyed;
 *   - otherwise x is destroyed and y's weight becomes y - x.
 *
 * Repeat until at most one stone is left. Return its weight, or 0 if none is
 * left.
 *
 * Example 1:
 *   Input:  stones = [2, 7, 4, 1, 8, 1]
 *   Output: 1
 *   Why:    8 and 7 make 1 -> [2, 4, 1, 1, 1]; 4 and 2 make 2 -> [2, 1, 1, 1];
 *           2 and 1 make 1 -> [1, 1, 1]; 1 and 1 vanish -> [1].
 *
 * Example 2:
 *   Input:  stones = [1]
 *   Output: 1
 *
 * Constraints:
 *   1 <= stones.length <= 30
 *   1 <= stones[i] <= 1000
 *
 * Target: O(n log n) with a max-heap (std::priority_queue).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_lastStoneWeight.cpp && ./a.out
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

    struct Case { vector<int> stones; int expected; };
    vector<Case> cases = {
        {{2, 7, 4, 1, 8, 1}, 1},
        {{1}, 1},
        {{2, 2}, 0},
        {{1, 3}, 2},
        {{10, 4, 2, 10}, 2},
        {{3, 7, 2}, 2},
        {{1, 1, 1}, 1},
        {{1000, 1}, 999},
    };
    for (auto& c : cases) check(sol.lastStoneWeight(c.stones), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
