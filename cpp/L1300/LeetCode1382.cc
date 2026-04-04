#include "../heads/tree_node.h"
#include <stack>
#include <vector>

class Solution {
    TreeNode* buildBalanceTree(std::vector<int> const &vals, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode *node = new TreeNode(vals[mid]);
        node->left = buildBalanceTree(vals, left, mid - 1);
        node->right = buildBalanceTree(vals, mid + 1, right);
        return node;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        std::vector<int> vals;
        std::stack<TreeNode*> nodes;
        TreeNode *node = root;
        while (node != nullptr || !nodes.empty()) {
            while (node != nullptr) {
                nodes.push(node);
                node = node->left;
            }
            node = nodes.top();
            nodes.pop();
            vals.emplace_back(node->val);
            node = node->right;
        }
        return buildBalanceTree(vals, 0, vals.size() - 1);
    }
};
