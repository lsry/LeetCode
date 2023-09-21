#include "../heads/tree_node.h"
#include <algorithm>
#include <utility>

class Solution {
    std::pair<int, int> robLevel(TreeNode *node) {
        if (node == nullptr) {
            return {0, 0};
        }
        auto [x1, y1] = robLevel(node->left);
        auto [x2, y2] = robLevel(node->right);
        return {node->val + y1 + y2, std::max(x1, y1) + std::max(x2, y2)};
    }
public:
    int rob(TreeNode* root) {
        auto [x, y] = robLevel(root);
        return std::max(x, y);
    }
};