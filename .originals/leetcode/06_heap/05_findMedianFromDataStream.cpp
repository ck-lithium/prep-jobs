/*
 * Find Median from Data Stream
 * LeetCode 295 (Hard) - https://leetcode.com/problems/find-median-from-data-stream/
 *
 * The median of a list of numbers is the middle value once the list is
 * sorted. With an even count, it's the average of the two middle values:
 * the median of [2, 3, 4] is 3, and the median of [2, 3] is 2.5.
 *
 * Implement the MedianFinder class:
 *   MedianFinder()          Creates an empty structure.
 *   void addNum(int num)    Adds a number.
 *   double findMedian()     Returns the median of all numbers added so far.
 *
 * Example:
 *   MedianFinder mf;
 *   mf.addNum(1);
 *   mf.addNum(2);
 *   mf.findMedian();   // returns 1.5
 *   mf.addNum(3);
 *   mf.findMedian();   // returns 2.0
 *
 * Constraints:
 *   -10^5 <= num <= 10^5
 *   findMedian is only called after at least one addNum.
 *   At most 5 * 10^4 calls in total.
 *
 * Target: O(log n) per addNum and O(1) per findMedian. Hint: keep the smaller
 * half of the numbers in a max-heap and the larger half in a min-heap.
 */

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        // TODO
    }

    void addNum(int num) {
        // TODO
    }

    double findMedian() {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_findMedianFromDataStream.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(long long x) { return to_string(x); }
string str(double x) {
    ostringstream out;
    out << fixed << setprecision(1) << x;
    return out.str();
}

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
        MedianFinder mf;
        mf.addNum(1);
        mf.addNum(2);
        check(mf.findMedian(), 1.5);
        mf.addNum(3);
        check(mf.findMedian(), 2.0);
    }
    // Negative numbers.
    {
        MedianFinder mf;
        vector<double> expected = {-1.0, -1.5, -2.0, -2.5, -3.0};
        for (int i = 1; i <= 5; i++) {
            mf.addNum(-i);
            check(mf.findMedian(), expected[i - 1]);
        }
    }
    // Duplicates, in no particular order.
    {
        MedianFinder mf;
        vector<int> nums = {6, 10, 2, 6, 5, 0, 6, 3, 1, 0, 0};
        vector<double> expected = {6.0, 8.0, 6.0, 6.0, 6.0, 5.5, 6.0, 5.5, 5.0, 4.0, 3.0};
        for (size_t i = 0; i < nums.size(); i++) {
            mf.addNum(nums[i]);
            check(mf.findMedian(), expected[i]);
        }
    }
    // Big input: 50000 numbers added as 0, 49999, 1, 49998, 2, ..., asking for
    // the median after every one. Re-sorting on every call is far too slow.
    // Adds up 2 * median over all calls; see the comment below for the value.
    {
        MedianFinder mf;
        long long sum = 0;
        for (int i = 0; i < 50000; i++) {
            mf.addNum(i % 2 == 0 ? i / 2 : 49999 - i / 2);
            sum += (long long)llround(2 * mf.findMedian());
        }
        // After an odd count 2m+1 the median is m; after an even count it's
        // 24999.5. So the sum is 2 * (0 + 1 + ... + 24999) + 25000 * 49999.
        check(sum, 1874950000LL);
    }

    cout << passed << "/" << total << " tests passed\n";
}
