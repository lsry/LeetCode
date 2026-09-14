#include "../heads/tree_node.h"

struct RN {
    int count;
    int sum;
    int equalCount;

    RN(int count, int sum, int equalCount): count(count), sum(sum), equalCount(equalCount) {}
};

class Solution {

    RN postOrder(TreeNode *node) {
        if (node == nullptr) {
            return RN(0, 0, 0);
        }
        RN left = postOrder(node->left);
        RN right = postOrder(node->right);
        RN cur(left.count + right.count + 1, left.sum + right.sum + node->val, left.equalCount + right.equalCount);
        if (cur.sum / cur.count == node->val) {
            cur.equalCount++;
        }
        return cur;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        RN cur = postOrder(root);
        return cur.equalCount;
    }
};
