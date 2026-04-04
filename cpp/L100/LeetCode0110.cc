#include "../heads/tree_node.h"
#include <algorithm>

class Solution {
    std::pair<bool, int> balanceTree(TreeNode *node) {
        if (node == nullptr) {
            return {true, 0};
        }
        auto [bl, nl] = balanceTree(node -> left);
        auto [br, nr] = balanceTree(node -> right);
        bool b = bl && br && std::abs(nl - nr) <= 1;
        return {b, std::max(nl, nr) + 1};
    }
public:
    bool isBalanced(TreeNode* root) {
        return balanceTree(root).first;
    }
};
