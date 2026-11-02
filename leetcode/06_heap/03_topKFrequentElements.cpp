/*
 * Top K Frequent Elements
 * LeetCode 347 (Medium) - https://leetcode.com/problems/top-k-frequent-elements/
 *
 * Given an integer array `nums` and an integer `k`, return the `k` values that
 * appear most often. You can return them in any order. The tests guarantee the
 * answer is unique (no ties at the cut-off).
 *
 * Example 1:
 *   Input:  nums = [1, 1, 1, 2, 2, 3], k = 2
 *   Output: [1, 2]
 *
 * Example 2:
 *   Input:  nums = [1], k = 1
 *   Output: [1]
 *
 * Constraints:
 *   1 <= nums.length <= 10^5
 *   -10^4 <= nums[i] <= 10^4
 *   k is between 1 and the number of distinct values.
 *
 * Target: better than O(n log n). Count with a hash map, then either keep a
 * min-heap of size k (O(n log k)) or put values into buckets by count (O(n)).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_topKFrequentElements.cpp && ./a.out
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

    struct Case { vector<int> nums; int k; vector<int> expected; };  // expected is sorted
    vector<Case> cases = {
        {{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
        {{1}, 1, {1}},
        {{4, 4, 4, 5, 5, 6}, 1, {4}},
        {{1, 2}, 2, {1, 2}},
        {{5, 3, 1, 1, 1, 3, 73, 1}, 2, {1, 3}},
        {{-1, -1, 2, 2, 2, 3}, 2, {-1, 2}},
    };
    for (auto& c : cases) {
        // Any order is accepted, so sort the answer before comparing.
        auto got = sol.topKFrequent(c.nums, c.k);
        sort(got.begin(), got.end());
        check(got, c.expected);
    }

    // Big input: value v appears v + 1 times for v = 0..440 (97461 values).
    // The 3 most frequent are 438, 439 and 440.
    vector<int> big;
    for (int v = 0; v <= 440; v++) big.insert(big.end(), v + 1, v);
    auto got = sol.topKFrequent(big, 3);
    sort(got.begin(), got.end());
    check(got, vector<int>{438, 439, 440});

    cout << passed << "/" << total << " tests passed\n";
}
