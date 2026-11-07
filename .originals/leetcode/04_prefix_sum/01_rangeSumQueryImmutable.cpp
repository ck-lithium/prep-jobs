/*
 * Range Sum Query - Immutable
 * LeetCode 303 (Easy) - https://leetcode.com/problems/range-sum-query-immutable/
 *
 * Implement the NumArray class:
 *   NumArray(vector<int>& nums)     Stores the array.
 *   int sumRange(int left, int right)
 *                                   Returns nums[left] + ... + nums[right]
 *                                   (both ends included).
 *
 * sumRange is called many times on the same array, so make each call fast.
 *
 * Example:
 *   NumArray a([-2, 0, 3, -5, 2, -1]);
 *   a.sumRange(0, 2);   // returns 1   (-2 + 0 + 3)
 *   a.sumRange(2, 5);   // returns -1  (3 - 5 + 2 - 1)
 *   a.sumRange(0, 5);   // returns -3
 *
 * Constraints:
 *   1 <= nums.length <= 10^4
 *   -10^5 <= nums[i] <= 10^5
 *   0 <= left <= right < nums.length
 *   At most 10^4 calls to sumRange.
 *
 * Target: O(n) once in the constructor, then O(1) per sumRange call.
 */

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        // TODO
    }

    int sumRange(int left, int right) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_rangeSumQueryImmutable.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
string str(long long x) { return to_string(x); }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    // The example from the problem.
    {
        vector<int> nums = {-2, 0, 3, -5, 2, -1};
        NumArray a(nums);
        check(a.sumRange(0, 2), 1);
        check(a.sumRange(2, 5), -1);
        check(a.sumRange(0, 5), -3);
        check(a.sumRange(3, 3), -5);
    }
    // A single element.
    {
        vector<int> nums = {7};
        NumArray a(nums);
        check(a.sumRange(0, 0), 7);
    }
    // Big input: nums = 0, 1, ..., 9999 and 10^4 queries. Query i asks for
    // the sum of a .. 9999 - a with a = i % 100, which is (10000 - 2a) * 9999 / 2;
    // added up over all the queries that's 495000495000.
    {
        vector<int> nums(10000);
        iota(nums.begin(), nums.end(), 0);
        NumArray a(nums);
        long long sum = 0;
        for (int i = 0; i < 10000; i++) sum += a.sumRange(i % 100, 9999 - i % 100);
        check(sum, 495000495000LL);
    }

    cout << passed << "/" << total << " tests passed\n";
}
