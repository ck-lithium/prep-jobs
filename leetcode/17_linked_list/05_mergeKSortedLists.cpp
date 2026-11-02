/*
 * Merge k Sorted Lists
 * LeetCode 23 (Hard) - https://leetcode.com/problems/merge-k-sorted-lists/
 *
 * You are given an array of k linked lists, each sorted in ascending order.
 * Merge them all into one sorted linked list and return its head.
 *
 * Example 1:
 *   Input:  lists = [1 -> 4 -> 5, 1 -> 3 -> 4, 2 -> 6]
 *   Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
 *
 * Example 2:
 *   Input:  lists = []
 *   Output: (empty list)
 *
 * Example 3:
 *   Input:  lists = [(empty list)]
 *   Output: (empty list)
 *
 * Constraints:
 *   0 <= k <= 10^4
 *   0 <= length of each list <= 500
 *   -10^4 <= Node.val <= 10^4
 *   Each list is sorted in ascending order.
 *   At most 10^4 nodes in total.
 *
 * Target: O(N log k) for N nodes in total. Keep the current head of every list
 * in a min-heap and repeatedly take the smallest. (Merging the lists in pairs,
 * like merge sort, gives the same bound.)
 */

#include <bits/stdc++.h>
using namespace std;

// A list node, defined the same way as on LeetCode.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // TODO
        return nullptr;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_mergeKSortedLists.cpp && ./a.out
// ---------------------------------------------------------------------------

ListNode* makeList(const vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : values) tail = tail->next = new ListNode(v);
    return dummy.next;
}

// Stops after 100000 nodes, in case a bug left a cycle in the list.
vector<int> toVector(ListNode* head) {
    vector<int> out;
    for (; head && out.size() < 100000; head = head->next) out.push_back(head->val);
    return out;
}

string str(bool b) { return b ? "true" : "false"; }
string str(int x) { return to_string(x); }
template <typename T> string str(const vector<T>& v) {
    string out = "[";
    for (size_t i = 0; i < v.size(); i++) out += (i ? "," : "") + str(v[i]);
    return out + "]";
}

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { vector<vector<int>> lists; vector<int> expected; };
    vector<Case> cases = {
        {{{1, 4, 5}, {1, 3, 4}, {2, 6}}, {1, 1, 2, 3, 4, 4, 5, 6}},
        {{}, {}},
        {{{}}, {}},
        {{{1}, {0}}, {0, 1}},
        {{{}, {1}}, {1}},
        {{{5, 5}, {5}}, {5, 5, 5}},
        {{{-2, -1}, {-3}, {}}, {-3, -2, -1}},
    };
    for (auto& c : cases) {
        vector<ListNode*> lists;
        for (auto& l : c.lists) lists.push_back(makeList(l));
        check(toVector(sol.mergeKLists(lists)), c.expected);
    }

    // Big input: 10^4 one-node lists holding 9999, 9998, ..., 0.
    // (Prints true/false only.)
    vector<ListNode*> lists;
    vector<int> expected(10000);
    for (int i = 0; i < 10000; i++) lists.push_back(new ListNode(9999 - i)), expected[i] = i;
    check(toVector(sol.mergeKLists(lists)) == expected, true);

    cout << passed << "/" << total << " tests passed\n";
}
