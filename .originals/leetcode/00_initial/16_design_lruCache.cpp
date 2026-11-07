/*
 * 16 - DESIGN: LRU Cache
 * LeetCode 146 (Medium) - https://leetcode.com/problems/lru-cache/
 *
 * Design a cache with a fixed capacity. When it is full and a new key is added,
 * it throws out the Least Recently Used key.
 *
 * Implement the LRUCache class:
 *   LRUCache(int capacity)       Creates the cache. capacity is positive.
 *   int get(int key)             Returns the value stored for key, or -1 if the
 *                                key isn't in the cache.
 *   void put(int key, int value) Stores value for key, adding the key if it is
 *                                new. If this makes the cache hold more than
 *                                `capacity` keys, remove the least recently
 *                                used key.
 *
 * Both get and put count as "using" a key. Both must run in O(1) average time.
 *
 * Example:
 *   LRUCache cache(2);
 *   cache.put(1, 1);   // cache holds {1=1}
 *   cache.put(2, 2);   // cache holds {1=1, 2=2}
 *   cache.get(1);      // returns 1; key 1 is now the most recently used
 *   cache.put(3, 3);   // full, so evict key 2 (least recently used) -> {1=1, 3=3}
 *   cache.get(2);      // returns -1
 *   cache.put(4, 4);   // full, so evict key 1 -> {3=3, 4=4}
 *   cache.get(1);      // returns -1
 *   cache.get(3);      // returns 3
 *   cache.get(4);      // returns 4
 *
 * Constraints:
 *   1 <= capacity <= 3000
 *   0 <= key <= 10^4
 *   0 <= value <= 10^5
 *   At most 2 * 10^5 calls to get and put in total.
 *
 * Target: O(1) average time for both get and put.
 *
 * How to spot this pattern: "implement a class whose operations are all O(1)".
 * The answer is usually two data structures working together, for example a
 * hash map plus a linked list.
 */

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
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
//   g++ -std=c++17 -O2 -Wall 16_design_lruCache.cpp && ./a.out
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
    // The example from the problem.
    {
        LRUCache cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        check(cache.get(1), 1);
        cache.put(3, 3);
        check(cache.get(2), -1);
        cache.put(4, 4);
        check(cache.get(1), -1);
        check(cache.get(3), 3);
        check(cache.get(4), 4);
    }
    // Capacity 1.
    {
        LRUCache cache(1);
        cache.put(2, 1);
        check(cache.get(2), 1);
        cache.put(3, 2);
        check(cache.get(2), -1);
        check(cache.get(3), 2);
    }
    // Updating an existing key also makes it the most recently used.
    {
        LRUCache cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        cache.put(1, 10);
        cache.put(3, 3);  // evicts key 2, not key 1
        check(cache.get(1), 10);
        check(cache.get(2), -1);
        check(cache.get(3), 3);
    }
    // Updating a key must not grow the cache.
    {
        LRUCache cache(2);
        cache.put(2, 1);
        cache.put(1, 1);
        cache.put(2, 3);
        cache.put(4, 1);  // evicts key 1
        check(cache.get(1), -1);
        check(cache.get(2), 3);
    }

    cout << passed << "/" << total << " tests passed\n";
}
