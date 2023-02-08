#include "heads/tree_node.h"
#include <queue>

class Solution {
    int treeCount(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + treeCount(root->left) + treeCount(root->right);
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *parent{nullptr}, *cur{nullptr};
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node{q.front()};
            q.pop();
            if (node->val == x) {
                cur = node;
                break;
            } 
            if (node->left != nullptr) {
                if (node->left->val == x) {
                    cur = node->left;
                    parent = node;
                    break;
                } else {
                    q.push(node->left);
                }
            }
            if (node->right != nullptr) {
                if (node->right->val == x) {
                    cur = node->right;
                    parent = node;
                    break;
                } else {
                    q.push(node->right);
                }
            }
        }
        int ln{treeCount(cur->left)}, rn{treeCount(cur->right)};
        if (parent == nullptr) {
            return ln > 1 + rn || rn > 1 + ln;
        }
        int cn{ln + rn + 1};
        return (n - cn) > cn || ln > (n - ln) || rn > (n - rn);
    }
};