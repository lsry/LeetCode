#include <stack>
using std::stack;

#include <vector>
using std::vector;

#include "heads/tree_node.h"

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> st1, st2;
        TreeNode *n1 = root1, *n2 = root2;
        while (!st1.empty() || !st2.empty() || n1 != nullptr || n2 != nullptr) {
            if (n1 != nullptr) {
                while (n1 != nullptr) {
                    st1.push(n1);
                    n1 = n1->left;
                }
            }
            if (n2 != nullptr) {
                while (n2 != nullptr) {
                    st2.push(n2);
                    n2 = n2->left;
                }
            }
            if (!st1.empty()) {
                n1 = st1.top();
            }
            if (!st2.empty()) {
                n2 = st2.top();
            }
            if (n1 != nullptr && n2 != nullptr) {
                if (n1->val <= n2->val) {
                    res.push_back(n1->val);
                    n1 = n1->right;
                    st1.pop();
                    n2 = nullptr;
                } else {
                    res.push_back(n2->val);
                    n2 = n2->right;
                    st2.pop();
                    n1 = nullptr;
                }
            } else if (n1 != nullptr) {
                res.push_back(n1->val);
                n1 = n1->right;
                st1.pop();
            } else {
                res.push_back(n2->val);
                n2 = n2->right;
                st2.pop();
            }
        }
        return res;
    }
};