#include "../heads/tree_node.h"
#include <utility>

class Solution {
    std::pair<TreeNode*, int> dfs(TreeNode* node, int level) {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr)) {
            return std::pair<TreeNode*, int>(node, level);
        }
        std::pair<TreeNode*, int> ln = dfs(node->left, level + 1);
        std::pair<TreeNode*, int> rn = dfs(node->right, level + 1);
        if (ln.first == nullptr) {
            return rn;
        } else if (rn.first == nullptr) {
            return ln;
        } else if (rn.second > ln.second) {
            return rn;
        } else if (ln.second > rn.second) {
            return ln;
        } else {
            return std::pair<TreeNode*, int>(node, ln.second);
        }
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto [n, l] = dfs(root, 0);
        return n;
    }
};
