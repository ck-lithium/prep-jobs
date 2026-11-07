/*
 * Design HashSet
 * LeetCode 705 (Easy) - https://leetcode.com/problems/design-hashset/
 *
 * Implement a hash set without using std::unordered_set, std::set or any
 * other built-in set or hash table.
 *
 * Implement the MyHashSet class:
 *   void add(int key)        Adds `key` (nothing happens if it's already in).
 *   bool contains(int key)   True if `key` is in the set.
 *   void remove(int key)     Removes `key` (nothing happens if it isn't in).
 *
 * Example:
 *   MyHashSet set;
 *   set.add(1);
 *   set.add(2);
 *   set.contains(1);   // true
 *   set.contains(3);   // false
 *   set.add(2);
 *   set.contains(2);   // true
 *   set.remove(2);
 *   set.contains(2);   // false
 *
 * Constraints:
 *   0 <= key <= 10^6
 *   At most 10^4 calls in total.
 *
 * Target: O(1) average per call. A fixed number of buckets, each a small
 * list, with key % buckets choosing the bucket ("separate chaining"). A plain
 * array of 10^6 + 1 booleans also works here; know why it wouldn't for
 * 64-bit keys.
 */

#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        // TODO
    }

    void add(int key) {
        // TODO
    }

    void remove(int key) {
        // TODO
    }

    bool contains(int key) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_designHashSet.cpp && ./a.out
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
        MyHashSet set;
        set.add(1);
        set.add(2);
        check(set.contains(1), true);
        check(set.contains(3), false);
        set.add(2);
        check(set.contains(2), true);
        set.remove(2);
        check(set.contains(2), false);
    }
    // Edge keys, and removing something that isn't there.
    {
        MyHashSet set;
        set.remove(5);
        check(set.contains(5), false);
        set.add(0);
        set.add(1000000);
        check(set.contains(0), true);
        check(set.contains(1000000), true);
        check(set.contains(999999), false);
    }
    // Many keys that share remainders: 0, 1000, 2000, ... (5000 keys),
    // then remove every other one.
    {
        MyHashSet set;
        for (int i = 0; i < 5000; i++) set.add(i * 1000 % 1000001);
        for (int i = 0; i < 5000; i += 2) set.remove(i * 1000 % 1000001);
        int found = 0;
        for (int i = 0; i < 5000; i++) found += set.contains(i * 1000 % 1000001);
        check(found, 2500);
        check(set.contains(1000), true);   // i = 1 was kept
        check(set.contains(2000), false);  // i = 2 was removed
    }

    cout << passed << "/" << total << " tests passed\n";
}
