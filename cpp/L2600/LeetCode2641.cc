#include "../heads/tree_node.h"
#include <queue>

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->val = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        int nextLevelSum{0};
        if (root->left != nullptr) {
            nextLevelSum += root->left->val;
        }
        if (root->right != nullptr) {
            nextLevelSum += root->right->val;
        }
        while (!q.empty()) {
            int qz = q.size();
            int nextLevelSum2{0};
            for (int i = 0;i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                int sum = nextLevelSum;
                if (node->left != nullptr) {
                    sum -= node->left->val;
                    if (node->left->left != nullptr) {
                        nextLevelSum2 += node->left->left->val;
                    }
                    if (node->left->right != nullptr) {
                        nextLevelSum2 += node->left->right->val;
                    }
                }
                if (node->right != nullptr) {
                    sum -= node->right->val;
                    if (node->right->left != nullptr) {
                        nextLevelSum2 += node->right->left->val;
                    }
                    if (node->right->right != nullptr) {
                        nextLevelSum2 += node->right->right->val;
                    }
                }
                if (node->left != nullptr) {
                    node->left->val = sum;
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    node->right->val = sum;
                    q.push(node->right);
                }
            }
            nextLevelSum = nextLevelSum2;
        }
        return root;
    }
};