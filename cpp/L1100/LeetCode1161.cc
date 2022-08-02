#include "heads/tree_node.h"
#include <queue>
#include <numeric>

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == nullptr) {
            return -1;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int maxV = std::numeric_limits<int>::min();
        int maxLevel = -1, level = 1;
        while (!q.empty()) {
            std::size_t qz{q.size()};
            int sum{0};
            for (std::size_t i{0};i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (sum > maxV) {
                maxV = sum;
                maxLevel = level;
            }
            ++level;
        }
        return maxLevel;
    }
};