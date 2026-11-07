/*
 * Linked List Cycle
 * LeetCode 141 (Easy) - https://leetcode.com/problems/linked-list-cycle/
 *
 * Given the head of a linked list, return true if the list has a cycle: if
 * following `next` pointers from some node eventually leads back to it.
 *
 * (The tests build the cycle by linking the last node back to the node at
 * position `pos`, or to nothing when pos = -1. Your function only gets the
 * head.)
 *
 * Example 1:
 *   Input:  3 -> 2 -> 0 -> -4, with -4 linking back to 2 (pos = 1)
 *   Output: true
 *
 * Example 2:
 *   Input:  1 -> 2, with 2 linking back to 1 (pos = 0)
 *   Output: true
 *
 * Example 3:
 *   Input:  1 (pos = -1)
 *   Output: false
 *
 * Constraints:
 *   0 <= number of nodes <= 10^4
 *   -10^5 <= Node.val <= 10^5
 *
 * Target: O(n) time and O(1) extra memory. A set of visited nodes needs O(n)
 * memory; instead, move one pointer 1 step at a time and another 2 steps at a
 * time (Floyd's "tortoise and hare"). If there is a cycle, they meet.
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
    bool hasCycle(ListNode* head) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_linkedListCycle.cpp && ./a.out
// ---------------------------------------------------------------------------

// Builds the list and links the last node back to the node at `pos`.
ListNode* makeList(const vector<int>& values, int pos) {
    vector<ListNode*> nodes;
    for (int v : values) nodes.push_back(new ListNode(v));
    for (size_t i = 0; i + 1 < nodes.size(); i++) nodes[i]->next = nodes[i + 1];
    if (pos >= 0 && !nodes.empty()) nodes.back()->next = nodes[pos];
    return nodes.empty() ? nullptr : nodes[0];
}

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

    struct Case { vector<int> list; int pos; bool expected; };
    vector<Case> cases = {
        {{3, 2, 0, -4}, 1, true},
        {{1, 2}, 0, true},
        {{1}, -1, false},
        {{}, -1, false},
        {{1}, 0, true},               // a node pointing to itself
        {{1, 2, 3, 4, 5}, -1, false},
        {{1, 2, 3, 4, 5}, 4, true},   // the last node points to itself
        {{1, 2, 3, 4, 5}, 0, true},
    };
    for (auto& c : cases) check(sol.hasCycle(makeList(c.list, c.pos)), c.expected);

    // Big input: 10^4 nodes, the last linking back to the first.
    vector<int> big(10000, 7);
    check(sol.hasCycle(makeList(big, 0)), true);
    check(sol.hasCycle(makeList(big, -1)), false);

    cout << passed << "/" << total << " tests passed\n";
}
