/*
 * Maximum Depth of Binary Tree
 * LeetCode 104 (Easy) - https://leetcode.com/problems/maximum-depth-of-binary-tree/
 *
 * Given the root of a binary tree, return its maximum depth: the number of
 * nodes on the longest path from the root down to a leaf.
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
 *   Output: 3
 *
 * Example 2:
 *   Input:  root = [1, null, 2]
 *   Output: 2
 *
 * (Trees are written in LeetCode's level-order format: the nodes level by
 * level, left to right, with null where a child is missing.)
 *
 * Constraints:
 *   0 <= number of nodes <= 10^4
 *   -100 <= Node.val <= 100
 *
 * Target: O(n). One line of recursion: depth(node) = 1 + max(depth(left),
 * depth(right)). Then try it iteratively with a queue, level by level.
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
    int maxDepth(TreeNode* root) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 01_maximumDepth.cpp && ./a.out
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

int passed = 0, total = 0;
template <typename T> void check(const T& got, const T& expected) {
    total++;
    passed += (got == expected);
    cout << "Test " << total << ": " << (got == expected ? "PASS" : "FAIL")
         << "  got " << str(got) << ", expected " << str(expected) << "\n";
}

int main() {
    Solution sol;

    struct Case { vector<optional<int>> tree; int expected; };
    vector<Case> cases = {
        {{3, 9, 20, null, null, 15, 7}, 3},
        {{1, null, 2}, 2},
        {{}, 0},
        {{1}, 1},
        {{1, 2, null, 3, null, 4}, 4},     // a chain going left
        {{1, 2, 3, 4, 5, 6, 7}, 3},        // a full tree
    };
    for (auto& c : cases) check(sol.maxDepth(makeTree(c.tree)), c.expected);

    // Big input: a chain of 10^4 nodes going left.
    vector<optional<int>> chain = {0};
    for (int i = 1; i < 10000; i++) chain.push_back(i), chain.push_back(null);
    check(sol.maxDepth(makeTree(chain)), 10000);

    cout << passed << "/" << total << " tests passed\n";
}
