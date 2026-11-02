/*
 * Lowest Common Ancestor of a Binary Tree
 * LeetCode 236 (Medium) - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 *
 * Given a binary tree and two of its nodes p and q, return their lowest common
 * ancestor: the deepest node that has both p and q in its subtree. A node
 * counts as part of its own subtree, so a node can be its own ancestor.
 *
 * Example 1:
 *   Input:  root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4], p = 5, q = 1
 *
 *                 3
 *               /   \
 *              5     1
 *             / \   / \
 *            6   2 0   8
 *               / \
 *              7   4
 *
 *   Output: 3
 *
 * Example 2:
 *   Input:  the same tree, p = 5, q = 4
 *   Output: 5
 *   Why:    5 is an ancestor of 4, and of itself.
 *
 * Example 3:
 *   Input:  root = [1, 2], p = 1, q = 2
 *   Output: 1
 *
 * Constraints:
 *   2 <= number of nodes <= 10^5
 *   -10^9 <= Node.val <= 10^9, and all values are different.
 *   p != q, and both are in the tree.
 *
 * Target: O(n), one recursive pass. Ask each subtree "do you contain p or q?":
 * the first node where the answers come from both sides (or the node is p or
 * q itself) is the answer.
 */

#include <bits/stdc++.h>
using namespace std;

// A binary tree node, defined the same way as on LeetCode.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // TODO
        return nullptr;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 04_lowestCommonAncestor.cpp && ./a.out
// ---------------------------------------------------------------------------

// Builds a tree from LeetCode's level-order format: [3, 9, 20, null, null, 15, 7].
const optional<int> null = nullopt;
TreeNode* makeTree(const vector<optional<int>>& values) {
    if (values.empty() || !values[0]) return nullptr;
    TreeNode* root = new TreeNode(*values[0]);
    queue<TreeNode*> q;
    q.push(root);
    for (size_t i = 1; !q.empty() && i < values.size(); i += 2) {
        TreeNode* node = q.front();
        q.pop();
        if (values[i]) q.push(node->left = new TreeNode(*values[i]));
        if (i + 1 < values.size() && values[i + 1]) q.push(node->right = new TreeNode(*values[i + 1]));
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    return left ? left : findNode(root->right, val);
}

string str(TreeNode* node) { return node ? to_string(node->val) : "null"; }

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    vector<optional<int>> example = {3, 5, 1, 6, 2, 0, 8, null, null, 7, 4};
    struct Case { vector<optional<int>> tree; int p, q, expected; };
    vector<Case> cases = {
        {example, 5, 1, 3},
        {example, 5, 4, 5},
        {{1, 2}, 1, 2, 1},
        {example, 6, 4, 5},
        {example, 7, 8, 3},
        {example, 0, 8, 1},
        {example, 7, 4, 2},
    };
    for (auto& c : cases) {
        TreeNode* root = makeTree(c.tree);
        TreeNode* got = sol.lowestCommonAncestor(root, findNode(root, c.p), findNode(root, c.q));
        check(got, findNode(root, c.expected));
    }

    cout << passed << "/" << total << " tests passed\n";
}
