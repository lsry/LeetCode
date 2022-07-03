#include <queue>
#include "heads/tree_node.h"

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int leftVal = 0;
        while (!q.empty()) {
            std::size_t qz{q.size()};
            for (std::size_t i{0};i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                if (i == 0) {
                    leftVal = node->val;
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return leftVal;
    }
};