#include "heads/tree_node.h"

class Solution {
    bool canCut(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        bool r1 = canCut(root->left);
        if (r1) {
            root->left = nullptr;
        }
        bool r2 = canCut(root->right);
        if (r2) {
            root->right = nullptr;
        }
        return r1 && r2 && root->val == 0;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (canCut(root)) {
            return nullptr;
        }
        return root;
    }
};