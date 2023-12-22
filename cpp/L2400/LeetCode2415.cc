#include "../heads/tree_node.h"
#include <utility>
#include <vector>

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        std::vector<std::vector<TreeNode*>> q(2, std::vector<TreeNode*>());
        q[0].push_back(root);
        int id{0};
        int level{0};
        while (!q[id].empty()) {
            int sz = q[id].size();
            if (level % 2 == 1) {
                for (int i = 0, j = sz - 1;i < j;++i, --j) {
                    std::swap(q[id][i]->val, q[id][j]->val);
                }
            }
            for (int i = 0;i < sz;++i) {
                TreeNode *node = q[id][i];
                if (node->left != nullptr) {
                    q[1 - id].push_back(node->left);
                }
                if (node->right != nullptr) {
                    q[1 - id].push_back(node->right);
                }
            }
            q[id].clear();
            ++level;
            id = 1 - id;
        }
        return root;
    }
};