#include "heads/tree_node.h"

#include <string>
using std::string;

class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string left = tree2str(root->left);
        string right = tree2str(root->right);
        string cur = std::to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return cur;
        } else if (root->left == nullptr) {
            return cur + "()(" + right + ")";
        } else if (root->right == nullptr) {
            return cur + "(" + left + ")";
        } else {
            return cur + "(" + left + ")(" + right + ")";
        }
    }
};