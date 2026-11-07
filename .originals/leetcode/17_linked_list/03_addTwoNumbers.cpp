/*
 * Add Two Numbers
 * LeetCode 2 (Medium) - https://leetcode.com/problems/add-two-numbers/
 *
 * Two non-negative integers are stored as linked lists of their digits, in
 * reverse order: 342 is stored as 2 -> 4 -> 3. Add the two numbers and return
 * the sum as a list in the same format.
 *
 * Example 1:
 *   Input:  l1 = 2 -> 4 -> 3, l2 = 5 -> 6 -> 4
 *   Output: 7 -> 0 -> 8
 *   Why:    342 + 465 = 807.
 *
 * Example 2:
 *   Input:  l1 = 0, l2 = 0
 *   Output: 0
 *
 * Example 3:
 *   Input:  l1 = 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9, l2 = 9 -> 9 -> 9 -> 9
 *   Output: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1
 *
 * Constraints:
 *   1 <= number of nodes in each list <= 100
 *   0 <= Node.val <= 9
 *   The numbers have no leading zeros, except the number 0 itself.
 *
 * Target: O(max(n, m)), digit by digit with a carry, like adding on paper.
 * Converting the lists to integers doesn't work: 100 digits don't fit in any
 * integer type.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // TODO
        return nullptr;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_addTwoNumbers.cpp && ./a.out
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

    struct Case { vector<int> l1, l2; vector<int> expected; };
    vector<Case> cases = {
        {{2, 4, 3}, {5, 6, 4}, {7, 0, 8}},
        {{0}, {0}, {0}},
        {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}, {8, 9, 9, 9, 0, 0, 0, 1}},
        {{5}, {5}, {0, 1}},
        {{1}, {9, 9}, {0, 0, 1}},
        {{1, 8}, {0}, {1, 8}},
    };
    for (auto& c : cases) check(toVector(sol.addTwoNumbers(makeList(c.l1), makeList(c.l2))), c.expected);

    // Big input: 10^100 - 1 (a hundred 9s) plus 1 is 10^100.
    vector<int> nines(100, 9), expected(100, 0);
    expected.push_back(1);
    check(toVector(sol.addTwoNumbers(makeList(nines), makeList({1}))), expected);

    cout << passed << "/" << total << " tests passed\n";
}
