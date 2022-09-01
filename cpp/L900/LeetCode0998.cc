#include "heads/tree_node.h"

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *p = nullptr;
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->val > val) {
                p = node;
                node = node->right;
            } else {
                break;
            }
        }
        if (p == nullptr) {
            return new TreeNode(val, root, nullptr);
        }
        p->right = new TreeNode(val, node, nullptr);
        return root;
    }
};