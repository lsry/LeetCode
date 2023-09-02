#include <queue>
#include "../heads/tree_node.h"

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        std::queue<std::pair<TreeNode*, unsigned long long int>> q;
        if (root == nullptr) {
            return 0;
        }
        q.push({root, 0});
        unsigned long long int maxWidth{1ULL};
        while (!q.empty()) {
            std::size_t qz{q.size()};
            unsigned long long int v1{0ULL};
            for (std::size_t i{0};i < qz;++i) {
                std::pair<TreeNode*, int> cur = q.front();
                q.pop();
                if (i == 0) {
                    v1 = cur.second;
                } else {
                    maxWidth = std::max(maxWidth, cur.second - v1 + 1ULL);
                }
                if (cur.first->left != nullptr) {
                    q.push({cur.first->left, cur.second * 2ULL + 1ULL});
                }
                if (cur.first->right != nullptr) {
                    q.push({cur.first->right, cur.second * 2ULL + 2ULL});
                }
            }
        }
        return maxWidth;
    }
};