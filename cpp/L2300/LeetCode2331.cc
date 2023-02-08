#include "heads/tree_node.h"

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr) {
            return root->val;
        }
        bool l{evaluateTree(root->left)}, r{evaluateTree(root->right)};
        return root->val == 2 ? (l || r) : (l && r);
    }
};