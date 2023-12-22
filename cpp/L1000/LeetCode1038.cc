#include "../heads/tree_node.h"

class Solution {
    int trace(TreeNode *node, int sum) {
        if (node == nullptr) {
            return sum;
        }
        int rm{trace(node->right, sum)};
        node->val += rm;
        int lm{trace(node->left, node->val)};
        return lm;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        trace(root, 0);
        return root;
    }
};