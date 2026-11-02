/*
 * Remove K Digits
 * LeetCode 402 (Medium) - https://leetcode.com/problems/remove-k-digits/
 *
 * `num` is a non-negative integer written as a string. Remove exactly `k` of
 * its digits so that the number left is as small as possible, and return it.
 *
 * Don't return leading zeros ("0200" should be "200"), and return "0" if no
 * digits are left.
 *
 * Example 1:
 *   Input:  num = "1432219", k = 3
 *   Output: "1219"
 *   Why:    remove the 4, the 3 and one 2.
 *
 * Example 2:
 *   Input:  num = "10200", k = 1
 *   Output: "200"
 *   Why:    removing the 1 leaves "0200".
 *
 * Example 3:
 *   Input:  num = "10", k = 2
 *   Output: "0"
 *
 * Constraints:
 *   1 <= k <= num.length <= 10^5
 *   num contains only digits and has no leading zeros (except "0" itself).
 *
 * Target: O(n). A smaller digit as early as possible matters most: whenever a
 * digit is bigger than the one after it, removing it helps.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // TODO
        return "";
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_removeKDigits.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }
string str(const string& s) { return '"' + s + '"'; }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { string num; int k; string expected; };
    vector<Case> cases = {
        {"1432219", 3, "1219"},
        {"10200", 1, "200"},
        {"10", 2, "0"},
        {"9", 1, "0"},
        {"112", 1, "11"},
        {"12345", 2, "123"},
        {"54321", 2, "321"},
        {"100200", 1, "200"},
        {"10001", 4, "0"},
        {"1234567890", 9, "0"},
    };
    for (auto& c : cases) check(sol.removeKdigits(c.num, c.k), c.expected);

    // Big input: 50000 ones followed by 50000 nines, k = 50000: remove every 9.
    // Rescanning from the start for each removal (O(n * k)) takes almost a
    // second here; a stack takes milliseconds. (Prints true/false only.)
    string big = string(50000, '1') + string(50000, '9');
    check(sol.removeKdigits(big, 50000) == string(50000, '1'), true);

    cout << passed << "/" << total << " tests passed\n";
}
