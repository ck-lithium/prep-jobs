/*
 * Valid Palindrome
 * LeetCode 125 (Easy) - https://leetcode.com/problems/valid-palindrome/
 *
 * A phrase is a palindrome if, after turning all uppercase letters into
 * lowercase and removing every character that is not a letter or a digit, it
 * reads the same forwards and backwards.
 *
 * Given a string `s`, return true if it is a palindrome.
 *
 * Example 1:
 *   Input:  s = "A man, a plan, a canal: Panama"
 *   Output: true
 *   Why:    it becomes "amanaplanacanalpanama".
 *
 * Example 2:
 *   Input:  s = "race a car"
 *   Output: false
 *   Why:    "raceacar" is not a palindrome.
 *
 * Example 3:
 *   Input:  s = " "
 *   Output: true
 *   Why:    nothing is left after removing the space, and "" is a palindrome.
 *
 * Constraints:
 *   1 <= s.length <= 2 * 10^5
 *   s contains only printable ASCII characters.
 *
 * Target: O(n) time, O(1) extra space (don't build the cleaned-up string).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_validPalindrome.cpp && ./a.out
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

    struct Case { string s; bool expected; };
    vector<Case> cases = {
        {"A man, a plan, a canal: Panama", true},
        {"race a car", false},
        {" ", true},
        {"0P", false},
        {"ab_a", true},
        {"Aa", true},
        {".,", true},
        {"No 'x' in Nixon", true},
        {"12321", true},
        {"123ab321", false},
    };
    for (auto& c : cases) check(sol.isPalindrome(c.s), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
