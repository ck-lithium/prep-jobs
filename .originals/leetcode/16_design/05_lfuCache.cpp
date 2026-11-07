/*
 * LFU Cache
 * LeetCode 460 (Hard) - https://leetcode.com/problems/lfu-cache/
 *
 * Design a cache with a fixed capacity that, when full, throws out the Least
 * Frequently Used key. If several keys are tied for the lowest use count, it
 * throws out the least recently used of them.
 *
 * Implement the LFUCache class:
 *   LFUCache(int capacity)       Creates the cache.
 *   int get(int key)             Returns the key's value, or -1 if the key
 *                                isn't in the cache.
 *   void put(int key, int value) Sets the key's value, adding the key if it's
 *                                new. If adding it would exceed the capacity,
 *                                first evict the key chosen by the rule above.
 *
 * Each key has a use counter: it starts at 1 when the key is added, and every
 * get or put on the key adds 1. A key that gets evicted loses its counter.
 *
 * Example:
 *   LFUCache c(2);
 *   c.put(1, 1);   // counts: 1->1
 *   c.put(2, 2);   // counts: 1->1, 2->1
 *   c.get(1);      // returns 1; counts: 1->2, 2->1
 *   c.put(3, 3);   // full: 2 has the lowest count, evict it. 1->2, 3->1
 *   c.get(2);      // returns -1
 *   c.get(3);      // returns 3; counts: 1->2, 3->2
 *   c.put(4, 4);   // full: 1 and 3 are tied at 2; 1 was used less recently,
 *                  // so evict 1. 3->2, 4->1
 *   c.get(1);      // returns -1
 *   c.get(3);      // returns 3
 *   c.get(4);      // returns 4
 *
 * Constraints:
 *   1 <= capacity <= 10^4
 *   0 <= key <= 10^5
 *   0 <= value <= 10^9
 *   At most 2 * 10^5 calls to get and put in total.
 *
 * Target: O(1) average for both get and put. LRU Cache (problem 16 of the
 * initial set) used one linked list; here keep one list per use count, plus
 * the smallest count currently in the cache.
 */

#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        // TODO
    }

    int get(int key) {
        // TODO
        return 0;
    }

    void put(int key, int value) {
        // TODO
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_lfuCache.cpp && ./a.out
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
        LFUCache c(2);
        c.put(1, 1);
        c.put(2, 2);
        check(c.get(1), 1);
        c.put(3, 3);
        check(c.get(2), -1);
        check(c.get(3), 3);
        c.put(4, 4);
        check(c.get(1), -1);
        check(c.get(3), 3);
        check(c.get(4), 4);
    }
    // Capacity 1.
    {
        LFUCache c(1);
        c.put(1, 1);
        c.put(2, 2);
        check(c.get(1), -1);
        check(c.get(2), 2);
    }
    // put on an existing key also counts as a use.
    {
        LFUCache c(2);
        c.put(1, 1);
        c.put(2, 2);
        c.put(1, 10);   // 1 -> count 2
        c.put(3, 3);    // evicts 2
        check(c.get(2), -1);
        check(c.get(1), 10);
        check(c.get(3), 3);
    }
    // A tie on the lowest count goes to the least recently used key.
    {
        LFUCache c(2);
        c.put(1, 1);
        c.put(2, 2);
        c.put(3, 3);    // 1 and 2 both have count 1; 1 is older
        check(c.get(1), -1);
        check(c.get(2), 2);
        check(c.get(3), 3);
    }
    // Big input: capacity 10^4, 10^5 puts cycling through 15000 keys, then a
    // get for each key. Adds up what the gets return. Scanning the whole cache
    // to find what to evict takes over a second here.
    {
        LFUCache c(10000);
        for (int i = 0; i < 100000; i++) c.put(i % 15000, i);
        long long sum = 0;
        for (int k = 0; k < 15000; k++) sum += c.get(k);
        check(sum, 949990000LL);
    }

    cout << passed << "/" << total << " tests passed\n";
}
