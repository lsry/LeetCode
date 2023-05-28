#include "../heads/tree_node.h"
#include <utility>
#include <algorithm>

class Solution {
    bool afterOrder(TreeNode *root, int sum, int limit) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return sum + root->val < limit;
        }
        bool lb = afterOrder(root->left, sum + root->val, limit);
        bool rb = afterOrder(root->right, sum + root->val, limit);
        bool b;
        if (root->left == nullptr) {
            b = rb;
        } else if (root->right == nullptr) {
            b = lb;
        } else {
            b = lb && rb;
        }
        if (lb) {
            root->left = nullptr;
        }
        if (rb) {
            root->right = nullptr;
        }
        return b;
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        bool b = afterOrder(root, 0, limit);
        return b ? nullptr : root;
    }
};

int main(int argc, char const *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(-5);
    Solution s;
    s.sufficientSubset(root, -1);
    return 0;
}
