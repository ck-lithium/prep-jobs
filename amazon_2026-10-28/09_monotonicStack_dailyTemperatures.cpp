/*
 * 09 - MONOTONIC STACK: Daily Temperatures
 * LeetCode 739 (Medium) - https://leetcode.com/problems/daily-temperatures/
 *
 * You are given an array `temperatures` with one temperature per day. Return an
 * array `answer` where answer[i] is how many days after day i you have to wait
 * for a warmer temperature. If no later day is warmer, answer[i] = 0.
 *
 * Example 1:
 *   Input:  temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
 *   Output: [1, 1, 4, 2, 1, 1, 0, 0]
 *   Why:    after day 2 (75) the next warmer day is day 6 (76), 4 days later.
 *
 * Example 2:
 *   Input:  temperatures = [30, 40, 50, 60]
 *   Output: [1, 1, 1, 0]
 *
 * Example 3:
 *   Input:  temperatures = [30, 60, 90]
 *   Output: [1, 1, 0]
 *
 * Constraints:
 *   1 <= temperatures.length <= 10^5
 *   30 <= temperatures[i] <= 100
 *
 * Target: O(n) time.
 *
 * How to spot this pattern: "next greater / next smaller element", "how many
 * days until ...", stock spans, largest rectangle in a histogram.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 09_monotonicStack_dailyTemperatures.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }
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

    struct Case { vector<int> temperatures; vector<int> expected; };
    vector<Case> cases = {
        {{73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}},
        {{30, 40, 50, 60}, {1, 1, 1, 0}},
        {{30, 60, 90}, {1, 1, 0}},
        {{50, 50, 50}, {0, 0, 0}},
        {{90, 80, 70, 100}, {3, 2, 1, 0}},
        {{55}, {0}},
    };
    for (auto& c : cases) check(sol.dailyTemperatures(c.temperatures), c.expected);

    // Big input: 10^5 days, all 50 except a 51 at the end.
    // An O(n^2) solution takes ~1 s here (too slow for the OA's time limit); an
    // O(n) one finishes instantly. (Prints true/false only.)
    vector<int> big(100000, 50);
    big.back() = 51;
    vector<int> bigExpected(100000);
    for (int i = 0; i < 100000; i++) bigExpected[i] = 99999 - i;
    check(sol.dailyTemperatures(big) == bigExpected, true);

    cout << passed << "/" << total << " tests passed\n";
}
