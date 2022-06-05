#include "heads/tree_node.h"

class Solution {
private:
    int dfsRecur(TreeNode *node, int num) {
        if (node == nullptr) {
            return 0;
        }
        num = num * 2 + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return num;
        } else if (node->right == nullptr) {
            return dfsRecur(node->left, num);
        } else if (node->left == nullptr) {
            return dfsRecur(node->right, num);
        } else {
            return dfsRecur(node->left, num) + dfsRecur(node->right, num);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfsRecur(root, 0);
    }
};