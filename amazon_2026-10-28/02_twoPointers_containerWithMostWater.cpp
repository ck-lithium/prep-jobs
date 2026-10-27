/*
 * 02 - TWO POINTERS: Container With Most Water
 * LeetCode 11 (Medium) - https://leetcode.com/problems/container-with-most-water/
 *
 * You are given an array `height` of length n. Picture n vertical lines: line i
 * goes from (i, 0) up to (i, height[i]).
 *
 * Pick two lines. Together with the x-axis they form a container. Return the
 * largest amount of water such a container can hold. The container can't be
 * tilted, so the water level is set by the shorter line:
 *
 *   water(i, j) = (j - i) * min(height[i], height[j])
 *
 * Example 1:
 *   Input:  height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
 *   Output: 49
 *   Why:    lines at index 1 (height 8) and index 8 (height 7): 7 * 7 = 49.
 *
 * Example 2:
 *   Input:  height = [1, 1]
 *   Output: 1
 *
 * Constraints:
 *   2 <= height.length <= 10^5
 *   0 <= height[i] <= 10^4
 *
 * Target: O(n) time, O(1) extra space.
 *
 * How to spot this pattern: you're choosing a pair (i, j), and comparing the two
 * ends tells you one of them can never be part of a better answer, so you can
 * move it inward. Also common on sorted arrays (pair sums, 3Sum).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int head = 0, tail = height.size() - 1;
        int area = 0;
        int temp = 0;

        while (tail > head){
            temp = min(height[head],height[tail]) * (tail - head);
            if(temp > area) {
                area = temp;        
            }

            if (height[head] > height[tail]) tail --;
            else head++;
        }

        return area;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_twoPointers_containerWithMostWater.cpp && ./a.out
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

    struct Case { vector<int> height; int expected; };
    vector<Case> cases = {
        {{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
        {{1, 1}, 1},
        {{4, 3, 2, 1, 4}, 16},
        {{1, 2, 1}, 2},
        {{2, 3, 4, 5, 18, 17, 6}, 17},
        {{0, 0}, 0},
    };
    for (auto& c : cases) check(sol.maxArea(c.height), c.expected);

    // Big input: 10^5 lines. An O(n^2) solution takes ~2 s here (too slow for the
    // OA's time limit); an O(n) one finishes instantly.
    vector<int> big(100000, 10000);
    check(sol.maxArea(big), 999990000);

    cout << passed << "/" << total << " tests passed\n";
}
