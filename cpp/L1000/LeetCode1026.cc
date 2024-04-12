#include "../heads/tree_node.h"
#include <cstdlib>
#include <algorithm>

class Solution {
    int search(TreeNode *root, int minVal, int maxVal) {
        int a = maxVal - minVal;
        if (root == nullptr) {
            return a;
        }
        a = std::max(a, std::max(std::abs(root->val - minVal), std::abs(maxVal - root->val)));
        maxVal = std::max(maxVal, root->val);
        minVal = std::min(minVal, root->val);
        int b = search(root->left, minVal, maxVal);
        int c = search(root->right, minVal, maxVal);
        return std::max(a, std::max(b, c));
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return search(root, root->val, root->val);
    }
};