#include "../heads/tree_node.h"
#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        std::stack<TreeNode*> st;
        TreeNode *node = root;
        while (node != nullptr || !st.empty()) {
            while (node != nullptr && node->left != nullptr) {
                st.push(node);
                node = node->left;
            }
            if (node == nullptr) {
                node = st.top();
                st.pop();
            }
            res.push_back(node->val);
            node = node->right;
        }
        return res;
    }
};