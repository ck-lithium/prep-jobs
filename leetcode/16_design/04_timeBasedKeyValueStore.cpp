/*
 * Time Based Key-Value Store
 * LeetCode 981 (Medium) - https://leetcode.com/problems/time-based-key-value-store/
 *
 * Design a key-value store that keeps every version of each key's value, and
 * can return the value a key had at a given time.
 *
 * Implement the TimeMap class:
 *   TimeMap()   Creates an empty store.
 *   void set(string key, string value, int timestamp)
 *               Stores `value` for `key` at time `timestamp`.
 *   string get(string key, int timestamp)
 *               Returns the value stored for `key` at the latest time that is
 *               <= timestamp, or "" if there is none.
 *
 * Example:
 *   TimeMap m;
 *   m.set("foo", "bar", 1);
 *   m.get("foo", 1);     // "bar"
 *   m.get("foo", 3);     // "bar": nothing newer than time 1 yet
 *   m.set("foo", "bar2", 4);
 *   m.get("foo", 4);     // "bar2"
 *   m.get("foo", 5);     // "bar2"
 *
 * Constraints:
 *   1 <= key.length, value.length <= 100
 *   1 <= timestamp <= 10^7
 *   For each key, the timestamps passed to set are strictly increasing.
 *   At most 2 * 10^5 calls in total.
 *
 * Target: O(1) set and O(log n) get. Because each key's timestamps arrive in
 * increasing order, its versions are already sorted: binary search them.
 */

#include <bits/stdc++.h>
using namespace std;

class TimeMap {
public:
    TimeMap() {
        // TODO
    }

    void set(string key, string value, int timestamp) {
        // TODO
    }

    string get(string key, int timestamp) {
        // TODO
        return "";
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_timeBasedKeyValueStore.cpp && ./a.out
// ---------------------------------------------------------------------------

string str(int x) { return to_string(x); }
string str(const string& s) { return '"' + s + '"'; }

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
        TimeMap m;
        m.set("foo", "bar", 1);
        check(m.get("foo", 1), string("bar"));
        check(m.get("foo", 3), string("bar"));
        m.set("foo", "bar2", 4);
        check(m.get("foo", 4), string("bar2"));
        check(m.get("foo", 5), string("bar2"));
        check(m.get("foo", 0), string(""));        // before the first version
        check(m.get("missing", 10), string(""));   // unknown key
    }
    // Two keys with interleaved versions.
    {
        TimeMap m;
        m.set("a", "a1", 10);
        m.set("b", "b1", 15);
        m.set("a", "a2", 20);
        check(m.get("a", 15), string("a1"));
        check(m.get("b", 15), string("b1"));
        check(m.get("b", 14), string(""));
        check(m.get("a", 25), string("a2"));
    }
    // Big input: 10^5 versions of one key at times 1, 3, 5, ..., then 10^5
    // lookups at times 2, 4, 6, ... Scanning all versions on every get takes
    // far too long.
    {
        TimeMap m;
        for (int i = 0; i < 100000; i++) m.set("k", to_string(i), 2 * i + 1);
        int correct = 0;
        for (int i = 0; i < 100000; i++) correct += (m.get("k", 2 * i + 2) == to_string(i));
        check(correct, 100000);
    }

    cout << passed << "/" << total << " tests passed\n";
}
