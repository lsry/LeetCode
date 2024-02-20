#include "../heads/tree_node.h"
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using std::vector;

class Solution {
    void traceTree(TreeNode *root, int row, int col, std::map<int, vector<std::pair<int, int>>> &mp) {
        if (root == nullptr) {
            return;
        }
        mp[col].emplace_back(std::pair<int, int>(row, root->val));
        traceTree(root->left, row + 1, col - 1, mp);
        traceTree(root->right, row + 1, col + 1, mp);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::map<int, vector<std::pair<int, int>>> mp;
        traceTree(root, 0, 0, mp);
        vector<vector<int>> res;
        for (auto it{mp.begin()};it != mp.end();++it) {
            std::sort(it->second.begin(), it->second.end(), [](std::pair<int, int> const &p1, std::pair<int, int> const &p2) {
                return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
            });
            vector<int> r(it->second.size());
            std::transform(it->second.begin(), it->second.end(), r.begin(), [](std::pair<int, int> const &p) {
                return p.second;
            });
            res.push_back(r);
        }
        return res;
    }
};