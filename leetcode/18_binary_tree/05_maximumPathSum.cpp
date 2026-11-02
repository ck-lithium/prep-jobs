/*
 * Binary Tree Maximum Path Sum
 * LeetCode 124 (Hard) - https://leetcode.com/problems/binary-tree-maximum-path-sum/
 *
 * A path in a binary tree is a sequence of nodes where each pair of neighbours
 * is joined by an edge, and no node appears twice. A path has at least one
 * node and doesn't have to go through the root. Its sum is the sum of its
 * nodes' values.
 *
 * Given the root of a binary tree, return the largest sum of any path.
 *
 * Example 1:
 *   Input:  root = [1, 2, 3]
 *   Output: 6
 *   Why:    2 -> 1 -> 3.
 *
 * Example 2:
 *   Input:  root = [-10, 9, 20, null, null, 15, 7]
 *
 *              -10
 *              /  \
 *             9    20
 *                 /  \
 *                15   7
 *
 *   Output: 42
 *   Why:    15 -> 20 -> 7.
 *
 * Constraints:
 *   1 <= number of nodes <= 3 * 10^4
 *   -1000 <= Node.val <= 1000
 *
 * Target: O(n), one pass. For each node compute the best "downward" path that
 * starts at it (it may continue into one child, or neither). The best overall
 * path bends at some node: node + best downward path on the left + on the
 * right, leaving out any side that would make the sum smaller.
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
    int maxPathSum(TreeNode* root) {
        // TODO
        return 0;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 05_maximumPathSum.cpp && ./a.out
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
        {{1, 2, 3}, 6},
        {{-10, 9, 20, null, null, 15, 7}, 42},
        {{-3}, -3},                   // all negative: the path still needs one node
        {{2, -1}, 2},
        {{-1, -2, -3}, -1},
        {{5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1}, 48},
        {{1, -2, 3}, 4},
        {{10, 2, 10, 20, 1, null, -25, null, null, null, null, 3, 4}, 42},
    };
    for (auto& c : cases) check(sol.maxPathSum(makeTree(c.tree)), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
