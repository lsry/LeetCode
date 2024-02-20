#include "../heads/tree_node.h"
#include <stack>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        std::stack<TreeNode *> st;
        TreeNode *node = root;
        while (!st.empty() || node != nullptr) {
            if (node == nullptr) {
                node = st.top();
                st.pop();
            }
            res.push_back(node->val);
            if (node->right != nullptr) {
                st.push(node->right);
            }
            if (node->left != nullptr) {
                st.push(node->left);
            }
            node =  nullptr;
        }
        return res;
    }
};