#include <queue>
#include <vector>
using std::vector;
#include "../heads/tree_node.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            int qz = q.size();
            vector<int> level;
            for (int i = 0;i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            res.emplace_back(level);
        }
        return res;
    }
};