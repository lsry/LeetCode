#include "heads/tree_node.h"
#include <queue>

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        if (depth == 1) {
            TreeNode *head = new TreeNode(val);
            head->left = root;
            return head;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int curDepth = 1;
        while (!q.empty() && curDepth + 1 < depth) {
            std::size_t qz{q.size()};
            for (std::size_t i{0};i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ++curDepth;
        }
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            TreeNode *ln = new TreeNode(val, node->left, nullptr);
            TreeNode *rn = new TreeNode(val, nullptr, node->right);
            node->left = ln;
            node->right = rn;
        }
        return root;
    }
};