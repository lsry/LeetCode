#include "../heads/tree_node.h"
#include <tuple>

class Solution {
    std::tuple<TreeNode*, int> findAncesotr(TreeNode *node, int depth) {
        if (node == nullptr) {
            return std::tuple<TreeNode*, int>(nullptr, depth);
        }
        auto [ln, ld] = findAncesotr(node->left, depth + 1);
        auto [rn, rd] = findAncesotr(node->right, depth + 1);
        if (ln == nullptr && rn == nullptr) {
            return std::tuple(node, depth);
        } else if (rn == nullptr) {
            return std::tuple(ln, ld);
        } else if (ln == nullptr) {
            return std::tuple(rn, rd);
        } else if (ld > rd) {
            return std::tuple(ln, ld);
        } else if (rd > ld) {
            return std::tuple(rn, rd);
        } else {
            return std::tuple(node, ld);
        }
    } 
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        auto [n, d] = findAncesotr(root, 0);
        return n;
    }
};