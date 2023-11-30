#include "../heads/tree_node.h"
#include <array>

class Solution {
    void palindrom(TreeNode *node, std::array<int, 10> &counts, int &res) {
        counts[node->val] += 1;
        if (node->left == nullptr && node->right == nullptr) {
            int odd{0};
            for (int count : counts) {
                if (count % 2 != 0) {
                    ++odd;
                }
            }
            res += odd <= 1 ? 1 : 0;
            counts[node->val] -= 1;
            return;
        }
        if (node->left != nullptr) {
            palindrom(node->left, counts, res);
        }
        if (node->right != nullptr) {
            palindrom(node->right, counts, res);
        }
        counts[node->val] -= 1;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int res{0};
        std::array<int, 10> counts{{0}};
        palindrom(root, counts, res);
        return res;
    }
};