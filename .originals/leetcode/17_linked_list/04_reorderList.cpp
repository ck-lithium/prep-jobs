/*
 * Reorder List
 * LeetCode 143 (Medium) - https://leetcode.com/problems/reorder-list/
 *
 * A list L0 -> L1 -> ... -> Ln-1 -> Ln must be rearranged into
 *   L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
 * by changing the nodes' links (don't just change the values). The function
 * rearranges the list in place and returns nothing.
 *
 * Example 1:
 *   Input:  1 -> 2 -> 3 -> 4
 *   Output: 1 -> 4 -> 2 -> 3
 *
 * Example 2:
 *   Input:  1 -> 2 -> 3 -> 4 -> 5
 *   Output: 1 -> 5 -> 2 -> 4 -> 3
 *
 * Constraints:
 *   1 <= number of nodes <= 5 * 10^4
 *   1 <= Node.val <= 1000
 *
 * Target: O(n) time, O(1) extra space, in three steps you already know:
 * find the middle (slow and fast pointers), reverse the second half, then
 * merge the two halves by alternating nodes.
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
    void reorderList(ListNode* head) {
        // TODO
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_reorderList.cpp && ./a.out
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

    struct Case { vector<int> list; vector<int> expected; };
    vector<Case> cases = {
        {{1, 2, 3, 4}, {1, 4, 2, 3}},
        {{1, 2, 3, 4, 5}, {1, 5, 2, 4, 3}},
        {{1}, {1}},
        {{1, 2}, {1, 2}},
        {{1, 2, 3}, {1, 3, 2}},
        {{1, 2, 3, 4, 5, 6}, {1, 6, 2, 5, 3, 4}},
    };
    for (auto& c : cases) {
        ListNode* head = makeList(c.list);
        sol.reorderList(head);
        check(toVector(head), c.expected);
    }

    // Big input: 5 * 10^4 nodes. Walking to the tail again for every node
    // (O(n^2)) takes about half a second here, against about a millisecond
    // for O(n). (Prints true/false only.)
    int n = 50000;
    vector<int> big(n), expected;
    for (int i = 0; i < n; i++) big[i] = i % 1000 + 1;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
        expected.push_back(big[i]);
        if (i != j) expected.push_back(big[j]);
    }
    ListNode* head = makeList(big);
    sol.reorderList(head);
    check(toVector(head) == expected, true);

    cout << passed << "/" << total << " tests passed\n";
}
