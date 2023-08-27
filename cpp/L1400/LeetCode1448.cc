#include "../heads/tree_node.h"
#include <limits>

class Solution {
    int dfs(TreeNode *root, int val) {
        if (root == nullptr) {
            return 0;
        }
        int count = 0;
        if (root->val >= val) {
            count = 1;
            val = root->val;
        }
        count += dfs(root->left, val);
        count += dfs(root->right, val);
        return count;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, std::numeric_limits<int>::min());
    }
};