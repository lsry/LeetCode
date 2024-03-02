#include "../heads/tree_node.h"

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }
        int ans{0};
        if (root->val >= low && root->val <= high) {
            ans += root->val;
        }
        if (root->val >= low) {
            ans += rangeSumBST(root->left, low, high);
        }
        if (root->val <= high) {
            ans += rangeSumBST(root->right, low, high);
        }
        return ans;
    }
};