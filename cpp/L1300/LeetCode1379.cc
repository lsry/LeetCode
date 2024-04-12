#include "../heads/tree_node.h"
#include <queue>

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        std::queue<TreeNode*> oq, cq;
        if (original == nullptr || target == nullptr || cloned == nullptr) {
            return nullptr;
        }
        oq.push(original);
        cq.push(cloned);
        while (!oq.empty()) {
            TreeNode *on{oq.front()};
            TreeNode *cn{cq.front()};
            oq.pop();
            cq.pop();
            if (on == target) {
                return cn;
            }
            if (on->left != nullptr) {
                oq.push(on->left);
                cq.push(cn->left);
            }
            if (on->right != nullptr) {
                oq.push(on->right);
                cq.push(cn->right);
            }
        }
        return nullptr;
    }
};