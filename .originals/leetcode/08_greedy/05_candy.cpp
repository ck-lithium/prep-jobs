/*
 * Candy
 * LeetCode 135 (Hard) - https://leetcode.com/problems/candy/
 *
 * n children stand in a line, and child i has the rating ratings[i]. Hand out
 * candy so that:
 *   - every child gets at least one candy;
 *   - a child with a higher rating than a neighbour gets more candy than that
 *     neighbour.
 *
 * Return the minimum total number of candies.
 *
 * Example 1:
 *   Input:  ratings = [1, 0, 2]
 *   Output: 5
 *   Why:    2, 1, 2 candies.
 *
 * Example 2:
 *   Input:  ratings = [1, 2, 2]
 *   Output: 4
 *   Why:    1, 2, 1 candies. Equal neighbours don't need equal candy.
 *
 * Constraints:
 *   1 <= n <= 2 * 10^4
 *   0 <= ratings[i] <= 2 * 10^4
 *
 * Target: O(n). Two passes: one left to right for the left neighbours, one
 * right to left for the right neighbours.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_candy.cpp && ./a.out
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

    struct Case { vector<int> ratings; int expected; };
    vector<Case> cases = {
        {{1, 0, 2}, 5},
        {{1, 2, 2}, 4},
        {{1}, 1},
        {{1, 2, 3}, 6},
        {{3, 2, 1}, 6},
        {{1, 3, 2, 2, 1}, 7},
        {{1, 2, 87, 87, 87, 2, 1}, 13},
        {{2, 2, 2}, 3},
    };
    for (auto& c : cases) check(sol.candy(c.ratings), c.expected);

    // Big input: ratings 0, 1, ..., 19999, so 1 + 2 + ... + 20000 = 200010000.
    vector<int> big(20000);
    iota(big.begin(), big.end(), 0);
    check(sol.candy(big), 200010000);

    cout << passed << "/" << total << " tests passed\n";
}
