#include <vector>
using std::vector;
#include <string>
using std::string;
#include "heads/tree_node.h"

class Solution {
private:
    int getTreeHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(getTreeHeight(root->left), getTreeHeight(root->right));
    }
    void buildTreeFormat(vector<vector<string>> &res, int left, int right, int row, TreeNode *node) {
        if (node == nullptr || left > right) {
            return;
        }
        int mid = (left + right) / 2;
        res[row][mid] = std::to_string(node->val);
        buildTreeFormat(res, left, mid - 1, row + 1, node->left);
        buildTreeFormat(res, mid + 1, right, row + 1, node->right);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        int height = getTreeHeight(root);
        int width = (1 << height) - 1;
        vector<vector<string>> res(height, vector<string>(width, ""));
        buildTreeFormat(res, 0, width - 1, 0, root);
        return res;
    }
};