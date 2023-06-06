#include "heads/tree_node.h"

#include <vector>
using std::vector;
#include <unordered_set>

class Solution {
    TreeNode* deleteNode(TreeNode *cur, vector<TreeNode*> &nodes, std::unordered_set<int> const &deleted) {
        if (cur == nullptr) {
            return nullptr;
        }
        cur->left = deleteNode(cur->left, nodes, deleted);
        cur->right = deleteNode(cur->right, nodes, deleted);
        if (deleted.find(cur->val) != deleted.end()) {
            if (cur->left != nullptr) {
                nodes.push_back(cur->left);
            }
            
            if (cur->right != nullptr) {
                nodes.push_back(cur->right);
            }
            return nullptr;
        }
        return cur;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr) {
            return {};
        }
        std::unordered_set<int> deleted(to_delete.begin(), to_delete.end());
        vector<TreeNode*> nodes;
        TreeNode *cur = deleteNode(root, nodes, deleted);
        if (cur != nullptr) {
            nodes.push_back(cur);
        }
        return nodes;
    }
};