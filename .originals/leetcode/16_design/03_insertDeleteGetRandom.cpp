/*
 * Insert Delete GetRandom O(1)
 * LeetCode 380 (Medium) - https://leetcode.com/problems/insert-delete-getrandom-o1/
 *
 * Implement the RandomizedSet class:
 *   bool insert(int val)  Adds val if it isn't there. Returns true if it was
 *                         added, false if it was already in the set.
 *   bool remove(int val)  Removes val if it's there. Returns true if it was
 *                         removed, false if it wasn't in the set.
 *   int getRandom()       Returns a random element of the set. Every element
 *                         must be equally likely. The set is never empty when
 *                         this is called.
 *
 * Every operation must take O(1) time on average.
 *
 * Example:
 *   RandomizedSet s;
 *   s.insert(1);     // true
 *   s.remove(2);     // false: 2 isn't in the set
 *   s.insert(2);     // true
 *   s.getRandom();   // 1 or 2, each half the time
 *   s.remove(1);     // true
 *   s.insert(2);     // false: already there
 *   s.getRandom();   // 2
 *
 * Constraints:
 *   -2^31 <= val <= 2^31 - 1
 *   At most 2 * 10^5 calls in total.
 *
 * Target: O(1) average per call. A hash map gives O(1) insert and remove but
 * no random access; a vector gives random access but O(n) removal. Use both:
 * to remove from the vector in O(1), swap the element with the last one first.
 */

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        // TODO
    }

    bool insert(int val) {
        // TODO
        return false;
    }

    bool remove(int val) {
        // TODO
        return false;
    }

    int getRandom() {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_insertDeleteGetRandom.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(bool b) { return b ? "true" : "false"; }
string str(int x) { return to_string(x); }

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
        RandomizedSet s;
        check(s.insert(1), true);
        check(s.remove(2), false);
        check(s.insert(2), true);
        int r = s.getRandom();
        check(r == 1 || r == 2, true);
        check(s.remove(1), true);
        check(s.insert(2), false);
        check(s.getRandom(), 2);
    }
    // Every value must come up about equally often: 10 values, 100000 draws,
    // so about 10000 each. Allowing 8000-12000 is very generous for a fair
    // choice.
    {
        RandomizedSet s;
        for (int v = 0; v < 10; v++) s.insert(v);
        vector<int> count(10, 0);
        bool allMembers = true;
        for (int i = 0; i < 100000; i++) {
            int r = s.getRandom();
            if (r < 0 || r >= 10) allMembers = false; else count[r]++;
        }
        check(allMembers, true);
        check(*min_element(count.begin(), count.end()) >= 8000 &&
              *max_element(count.begin(), count.end()) <= 12000, true);
    }
    // Big input: insert 0..99999, remove the even ones, then draw 1000 times;
    // every draw must be odd. Searching a vector on every insert and remove
    // takes about a second here.
    {
        RandomizedSet s;
        for (int v = 0; v < 100000; v++) s.insert(v);
        bool removedAll = true;
        for (int v = 0; v < 100000; v += 2) removedAll &= s.remove(v);
        check(removedAll, true);
        bool allOdd = true;
        for (int i = 0; i < 1000; i++) allOdd &= (s.getRandom() % 2 == 1);
        check(allOdd, true);
        check(s.remove(0), false);
        check(s.insert(0), true);
    }

    cout << passed << "/" << total << " tests passed\n";
}
