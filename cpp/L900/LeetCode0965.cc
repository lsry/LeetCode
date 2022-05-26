#include "heads/tree_node.h"

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left != nullptr && root->val != root->left->val) {
            return false;
        }
        if (root->right != nullptr && root->val != root->right->val) {
            return false;
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};