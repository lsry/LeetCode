#include "../heads/tree_node.h"
#include <cstdlib>

class Solution {
    constexpr static long long int MOD{1'000'000'007};

    double sum_2{0.0};
    long long int target{0};

    long long int getTreeSum(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return node->val + getTreeSum(node->left) + getTreeSum(node->right);
    }

    long long int traceTree(TreeNode *node) {
        if (node == nullptr) {
            return 0LL;
        }
        long long int leftSum{traceTree(node->left)};
        long long int rightSum{traceTree(node->right)};
        if (std::abs(target * 1.0 - sum_2) > std::abs(leftSum * 1.0 - sum_2)) {
            target = leftSum;
        }
        if (std::abs(target * 1.0 - sum_2) > std::abs(rightSum * 1.0 - sum_2)) {
            target = rightSum;
        }
        return node->val + leftSum + rightSum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long int sum{getTreeSum(root)};
        sum_2 = sum * 0.5;
        target = 0;
        traceTree(root);
        long long int b = (sum - target) % MOD;
        long long int ans = (target % MOD) * (b % MOD) % MOD;
        return ans;
    }
};
