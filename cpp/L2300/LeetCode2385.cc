#include "../heads/tree_node.h"
#include <algorithm>
#include <queue>
#include <vector>

class Solution {
    void createGraph(TreeNode *node, TreeNode *parent, std::vector<std::vector<int>> &adjoints) {
        if (node == nullptr) {
            return;
        }
        if (parent != nullptr) {
            adjoints[parent->val].push_back(node->val);
            adjoints[node->val].push_back(parent->val);
        }
        createGraph(node->left, node, adjoints);
        createGraph(node->right, node, adjoints);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr) {
            return 0;
        }
        std::vector<std::vector<int>> adjoints(100001, std::vector<int>());
        createGraph(root, nullptr, adjoints);
        std::vector<bool> flags(100001, false);
        std::queue<int> q;
        q.push(start);
        int ans{0};
        flags[start] = true;
        while (!q.empty()) {
            int qz = q.size();
            for (int i = 0;i < qz;++i) {
                int cur = q.front();
                q.pop();
                for (int next : adjoints[cur]) {
                    if (!flags[next]) {
                        q.push(next);
                        flags[next] = true;
                    }
                }
            }
            ++ans;
        }
        return ans - 1;
    }
};