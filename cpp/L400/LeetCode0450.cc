#include "heads/tree_node.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *parent = nullptr;
        TreeNode *cur = root;
        while (cur != nullptr && cur->val != key) {
            parent = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (cur == nullptr) {
            return root;
        }
        TreeNode *childRoot = nullptr;
        if (cur->left != nullptr) {
            childRoot = cur->left;
            TreeNode *r = cur->left;
            while (r->right != nullptr) {
                r = r->right;
            }
            r->right = cur->right;
        } else if (cur->right != nullptr) {
            childRoot = cur->right;
        } else if (parent != nullptr) {
            if (parent->val > cur->val) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }
        if (parent == nullptr) {
            return childRoot;
        }
        if (childRoot == nullptr) {
            return root;
        }
        if (parent->val > childRoot->val) {
            parent->left = childRoot;
        } else {
            parent->right = childRoot;
        }
        return root;
    }
};