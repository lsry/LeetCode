#include "../heads/tree_node.h"
#include <functional>
#include <queue>
#include <vector>

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;
        std::queue<TreeNode*> q;
        if (root == nullptr) {
            return -1LL;
        }
        q.push(root);
        while (!q.empty()) {
            int qz = q.size();
            long long sum{0LL};
            for (int i = 0;i < qz;++i) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                sum += node->val;
            }
            pq.push(sum);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.size() < k ? -1LL : pq.top();
    }
};