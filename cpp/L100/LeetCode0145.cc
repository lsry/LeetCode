#include "../heads/tree_node.h"
#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode *node{root};
        TreeNode *prev{nullptr};
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            if (node->right == nullptr || node->right == prev) {
                res.emplace_back(node->val);
                prev = node;
                node = nullptr;
            } else {
                st.push(node);
                node = node->right;
            }
        }
        return res;
    }
};