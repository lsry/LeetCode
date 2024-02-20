#include "../heads/tree_node.h"
#include <deque>
#include <queue>
#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        bool left{true};
        while (!q.empty()) {
            int qz = q.size();
            std::deque<int> level;
            for (int i = 0;i < qz;++i) {
                TreeNode *node{q.front()};
                q.pop();
                if (left) {
                    level.push_back(node->val);
                } else {
                    level.push_front(node->val);
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            left = !left;
            res.emplace_back(vector<int>(level.begin(), level.end()));
        }
        return res;
    }
};

int main() {
    Solution s;
    TreeNode node(3);
    s.zigzagLevelOrder(&node);
}