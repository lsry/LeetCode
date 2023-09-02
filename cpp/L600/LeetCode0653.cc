#include "../heads/tree_node.h"

#include <stack>
using std::stack;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        stack<TreeNode*> lt, rt;
        TreeNode *node = root;
        while (node != nullptr) {
            lt.push(node);
            node = node->left;
        }
        TreeNode *ln = lt.top();
        lt.pop();
        node = root;
        while (node != nullptr) {
            rt.push(node);
            node = node->right;
        }
        TreeNode *rn = rt.top();
        rt.pop();
        while (ln != rn) {
            if (ln->val + rn->val == k) {
                return true;
            } else if (ln->val + rn->val < k) {
                ln = ln->right;
                while (ln != nullptr) {
                    lt.push(ln);
                    ln = ln->left;
                }
                if (lt.empty()) {
                    break;
                } else {
                    ln = lt.top();
                    lt.pop();
                }
            } else {
                rn = rn->left;
                while (rn != nullptr) {
                    rt.push(rn);
                    rn = rn->right;
                }
                if (rt.empty()) {
                    break;
                } else {
                    rn = rt.top();
                    rt.pop();
                }
            }
        }
        return false;
    }
};