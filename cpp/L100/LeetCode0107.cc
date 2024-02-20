#include "../heads/tree_node.h"
#include <algorithm>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
        std::reverse(res.begin(), res.end());
        return res;
    }
};