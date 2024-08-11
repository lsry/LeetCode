#include "../heads/tree_node.h"
#include <queue>

class Solution {
    bool sameTree(TreeNode *rootA, TreeNode *rootB) {
        if (rootA == nullptr && rootB == nullptr) {
            return true;
        }
        if (rootA == nullptr && rootB != nullptr || rootA != nullptr && rootB == nullptr) {
            return false;
        }
        return rootA->val == rootB->val 
           && sameTree(rootA->left, rootB->left) 
           && sameTree(rootA->right, rootB->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->val == subRoot->val && sameTree(node, subRoot)) {
                return true;
            }
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        return false;
    }
};