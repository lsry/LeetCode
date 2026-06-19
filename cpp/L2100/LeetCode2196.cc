#include "../heads/tree_node.h"
#include <unordered_map>
#include <vector>
using std::vector;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<int, bool> parents;
        std::unordered_map<int, TreeNode*> nodes;
        for (vector<int> const &desc : descriptions) {
            if (nodes.find(desc[0]) == nodes.end()) {
                nodes[desc[0]] = new TreeNode(desc[0]);
                parents[desc[0]] = true;
            }
            if (nodes.find(desc[1]) == nodes.end()) {
                nodes[desc[1]] = new TreeNode(desc[1]);
            }
            parents[desc[1]] = false;
            if (desc[2] == 1) {
                nodes[desc[0]]->left = nodes[desc[1]];
            } else {
                nodes[desc[0]]->right = nodes[desc[1]];
            }
        }
        for (auto const &[n, f] : parents) {
            if (f) {
                return nodes[n];
            }
        }
        return nullptr;
    }
};
