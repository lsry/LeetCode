#include "../heads/tree_node.h"
#include <unordered_set>

class FindElements {
    std::unordered_set<int> st;

    void recoverTree(TreeNode *node, int val) {
        if (node == nullptr) {
            return;
        }
        st.emplace(val);
        node->val = val;
        recoverTree(node->left, val * 2 + 1);
        recoverTree(node->right, val * 2 + 2);
    }
public:
    FindElements(TreeNode* root) {
        recoverTree(root, 0);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};