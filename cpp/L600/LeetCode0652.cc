#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <string>

#include "heads/tree_node.h"

class Solution {
private:
    unordered_map<std::string, std::pair<TreeNode*, bool>> map;
    vector<TreeNode*> res;
    std::string serialTree(TreeNode* node) {
        if (node == nullptr) {
            return "null";
        }
        std::string sl = serialTree(node->left), sr = serialTree(node->right);
        std::string rs = std::to_string(node->val) + "," + sl + "," + sr;
        if (map.find(rs) != map.end()) {
            std::pair<TreeNode*, bool> &nv = map[rs];
            if (nv.second == false) {
                nv.second = true;
                res.push_back(nv.first);
            }
        } else {
            map[rs] = {node, false};
        }
        return rs;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialTree(root);
        return res;
    }
};