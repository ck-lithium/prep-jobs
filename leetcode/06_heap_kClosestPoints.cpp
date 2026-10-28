/*
 * 06 - HEAP / TOP K: K Closest Points to Origin
 * LeetCode 973 (Medium) - https://leetcode.com/problems/k-closest-points-to-origin/
 *
 * You are given an array `points` where points[i] = [x_i, y_i] is a point on
 * the plane, and an integer `k`. Return the `k` points closest to the origin
 * (0, 0), using ordinary (Euclidean) distance: sqrt(x^2 + y^2).
 *
 * You can return the points in any order. The answer is guaranteed to be unique
 * apart from the order.
 *
 * Example 1:
 *   Input:  points = [[1, 3], [-2, 2]], k = 1
 *   Output: [[-2, 2]]
 *   Why:    (1, 3) is at distance sqrt(10), (-2, 2) is at sqrt(8), which is closer.
 *
 * Example 2:
 *   Input:  points = [[3, 3], [5, -1], [-2, 4]], k = 2
 *   Output: [[3, 3], [-2, 4]]   ([[-2, 4], [3, 3]] is also accepted)
 *
 * Constraints:
 *   1 <= k <= points.length <= 10^4
 *   -10^4 <= x_i, y_i <= 10^4
 *
 * Target: O(n log k) time, O(k) extra space.
 *
 * How to spot this pattern: "top k", "k smallest / largest", "k-th element", or
 * "keep taking the current smallest / largest item".
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 06_heap_kClosestPoints.cpp && ./a.out
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

    struct Case { vector<vector<int>> points; int k; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{{1, 3}, {-2, 2}}, 1, {{-2, 2}}},
        {{{3, 3}, {5, -1}, {-2, 4}}, 2, {{3, 3}, {-2, 4}}},
        {{{0, 1}, {1, 0}}, 2, {{0, 1}, {1, 0}}},
        {{{2, 2}, {1, 1}, {-1, -1}, {3, 3}}, 2, {{1, 1}, {-1, -1}}},
        {{{10000, 10000}, {-10000, -10000}, {0, 0}}, 1, {{0, 0}}},
    };
    for (auto& c : cases) {
        // Any order is accepted, so sort both before comparing.
        auto got = sol.kClosest(c.points, c.k);
        sort(got.begin(), got.end());
        sort(c.expected.begin(), c.expected.end());
        check(got, c.expected);
    }

    cout << passed << "/" << total << " tests passed\n";
}
