#include "../heads/tree_node.h"
#include <queue>

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        if (root == nullptr) {
            return res;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res = 0;
            std::size_t qz{q.size()};
            for (std::size_t i{0};i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                res += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};