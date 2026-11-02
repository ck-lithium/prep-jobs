/*
 * Validate Binary Search Tree
 * LeetCode 98 (Medium) - https://leetcode.com/problems/validate-binary-search-tree/
 *
 * Given the root of a binary tree, return true if it is a valid binary search
 * tree (BST):
 *   - every value in a node's left subtree is strictly less than the node's;
 *   - every value in its right subtree is strictly greater;
 *   - both subtrees are valid BSTs too.
 *
 * Example 1:
 *   Input:  root = [2, 1, 3]
 *   Output: true
 *
 * Example 2:
 *   Input:  root = [5, 1, 4, null, null, 3, 6]
 *
 *               5
 *              / \
 *             1   4
 *                / \
 *               3   6
 *
 *   Output: false
 *   Why:    4 is in 5's right subtree but is smaller than 5.
 *
 * Constraints:
 *   1 <= number of nodes <= 10^4
 *   -2^31 <= Node.val <= 2^31 - 1
 *
 * Target: O(n). Comparing each node only with its children isn't enough (see
 * the third test): pass down the range of values each subtree is allowed to
 * hold. Careful: the values can be INT_MIN and INT_MAX, so those can't double
 * as "no limit".
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
    bool isValidBST(TreeNode* root) {
        // TODO
        return false;
    }
};

// ---------------------------------------------------------------------------
// Tests. Build and run:
//   g++ -std=c++17 -O2 -Wall 03_validateBST.cpp && ./a.out
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

    struct Case { vector<optional<int>> tree; bool expected; };
    vector<Case> cases = {
        {{2, 1, 3}, true},
        {{5, 1, 4, null, null, 3, 6}, false},
        {{5, 4, 6, null, null, 3, 7}, false},   // 3 is a fine child of 6 but sits right of 5
        {{1}, true},
        {{1, 1}, false},                        // duplicates are not allowed
        {{2147483647}, true},
        {{-2147483647 - 1, null, 2147483647}, true},
        {{3, 1, 5, 0, 2, 4, 6}, true},
        {{2147483647, 2147483647}, false},
    };
    for (auto& c : cases) check(sol.isValidBST(makeTree(c.tree)), c.expected);

    cout << passed << "/" << total << " tests passed\n";
}
