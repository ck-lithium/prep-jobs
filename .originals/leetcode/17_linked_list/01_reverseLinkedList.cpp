/*
 * Reverse Linked List
 * LeetCode 206 (Easy) - https://leetcode.com/problems/reverse-linked-list/
 *
 * Given the head of a singly linked list, reverse the list and return the new
 * head.
 *
 * Example 1:
 *   Input:  1 -> 2 -> 3 -> 4 -> 5
 *   Output: 5 -> 4 -> 3 -> 2 -> 1
 *
 * Example 2:
 *   Input:  1 -> 2
 *   Output: 2 -> 1
 *
 * Example 3:
 *   Input:  (empty list)
 *   Output: (empty list)
 *
 * Constraints:
 *   0 <= number of nodes <= 5000
 *   -5000 <= Node.val <= 5000
 *
 * Target: O(n) time, O(1) extra space, by re-pointing each node's `next`.
 * Follow-up: write it both iteratively and recursively.
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
    ListNode* reverseList(ListNode* head) {
        // TODO
        return nullptr;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_reverseLinkedList.cpp && ./a.out
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

    struct Case { vector<int> list; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}},
        {{1, 2}, {2, 1}},
        {{}, {}},
        {{7}, {7}},
        {{1, 1, 2}, {2, 1, 1}},
        {{-5000, 0, 5000}, {5000, 0, -5000}},
    };
    for (auto& c : cases) check(toVector(sol.reverseList(makeList(c.list))), c.expected);

    // Big input: 5000 nodes.
    vector<int> big(5000), bigReversed(5000);
    for (int i = 0; i < 5000; i++) big[i] = i, bigReversed[i] = 4999 - i;
    check(toVector(sol.reverseList(makeList(big))), bigReversed);

    cout << passed << "/" << total << " tests passed\n";
}
