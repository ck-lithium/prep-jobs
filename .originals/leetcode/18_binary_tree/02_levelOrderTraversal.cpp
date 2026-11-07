/*
 * Binary Tree Level Order Traversal
 * LeetCode 102 (Medium) - https://leetcode.com/problems/binary-tree-level-order-traversal/
 *
 * Given the root of a binary tree, return the values of its nodes level by
 * level: one list per level, each from left to right.
 *
 * Example 1:
 *   Input:  root = [3, 9, 20, null, null, 15, 7]
 *
 *               3
 *              / \
 *             9   20
 *                /  \
 *               15   7
 *
 *   Output: [[3], [9, 20], [15, 7]]
 *
 * Example 2:
 *   Input:  root = [1]
 *   Output: [[1]]
 *
 * Example 3:
 *   Input:  root = []
 *   Output: []
 *
 * Constraints:
 *   0 <= number of nodes <= 2000
 *   -1000 <= Node.val <= 1000
 *
 * Target: O(n) with BFS. To know where each level ends, record the queue's
 * size at the start of the level and pop exactly that many nodes.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // TODO
        return {};
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 02_levelOrderTraversal.cpp && ./a.out
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

    struct Case { vector<optional<int>> tree; vector<vector<int>> expected; };
    vector<Case> cases = {
        {{3, 9, 20, null, null, 15, 7}, {{3}, {9, 20}, {15, 7}}},
        {{1}, {{1}}},
        {{}, {}},
        {{1, 2, 3, 4, null, null, 5}, {{1}, {2, 3}, {4, 5}}},
        {{1, null, 2, null, 3}, {{1}, {2}, {3}}},
        {{1, 2, 3, 4, 5, 6, 7}, {{1}, {2, 3}, {4, 5, 6, 7}}},
    };
    for (auto& c : cases) check(sol.levelOrder(makeTree(c.tree)), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
