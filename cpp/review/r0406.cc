#include "heads/tree_node.h"

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *parent{nullptr};
        while (root != nullptr && root->val != p->val) {
            if (root->val > p->val) {
                parent = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (root != nullptr && root->right != nullptr) {
            root = root->right;
            do {
                parent = root;
                root = root->left;
            } while (root != nullptr);
        }
        return parent;
    }
};