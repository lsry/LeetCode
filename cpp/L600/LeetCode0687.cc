#include "heads/tree_node.h"
#include <algorithm>

class Solution {
private:
    int maxPath{0};
    int helpPath(TreeNode *node, int path) {
        if (node == nullptr) {
            return path;
        }
        int lp = 0, rp = 0;
        if (node->left != nullptr) {
            if (node->left->val == node->val) {
                lp = helpPath(node->left, path + 1);
            } else {
                helpPath(node->left, 0);
            }
        }
        if (node->right != nullptr) {
            if (node->right->val == node->val) {
                rp = helpPath(node->right, path + 1);
            } else {
                helpPath(node->right, 0);
            }
        }
        /**
         * 路径一般三种情况：
         * 1/2：某一结点到其后代节点，从左子树或右子树出发。
         * 3：左子树后代结点经过当前结点到达右子树
         */
        path = path + std::max(lp, rp);
        maxPath = std::max(maxPath, std::max(path, lp + rp));
        return path;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        maxPath = 0;
        helpPath(root, 0);
        return maxPath;
    }
};