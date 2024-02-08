#include "../heads/tree_node.h"
#include <queue>

class Solution {
    bool sameParent(TreeNode *node, int x, int y) {
        return node->left != nullptr && (node->left->val == x || node->left->val == y)
         && node->right != nullptr && (node->right->val == x || node->right->val == y);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) {
            return false;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int count{0};
        while (!q.empty()) {
            int qz = q.size();
            for (int i = 0;i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                if (sameParent(node, x, y)) {
                    return false;
                }
                if (node->left != nullptr) {
                    if (node->left->val == x || node->left->val == y) {
                        ++count;
                    }
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    if (node->right->val == x || node->right->val == y) {
                        ++count;
                    }
                    q.push(node->right);
                }
            }
            if (count == 2) {
                return true;
            }
            count = 0;
        }
        return false;
    }
};