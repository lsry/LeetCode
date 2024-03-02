#include "../heads/tree_node.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
        TreeNode *ln = lowestCommonAncestor(root->left, p, q);
        TreeNode *rn = lowestCommonAncestor(root->right, p, q);
        if (rn == nullptr) {
            return ln;
        }
        if (ln == nullptr) {
            return rn;
        }
        return root;
    }
};