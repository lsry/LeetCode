#include "heads/tree_node.h"
#include <algorithm>

struct TreeResult {
    bool binary;
    TreeNode *minNode, *maxNode;
    int sum;

    TreeResult(bool binary, TreeNode *minNode, TreeNode *maxNode, int sum)
     :binary(binary), minNode(minNode), maxNode(maxNode), sum(sum) {}
};

class Solution {
    int binTreeSum;

    TreeResult afterOrder(TreeNode *root) {
        if (root == nullptr) {
            return TreeResult(true, nullptr, nullptr, 0);
        }
        TreeResult result(true, root, root, root->val);
        TreeResult rightResult{afterOrder(root->right)};
        TreeResult leftResult{afterOrder(root->left)};
        if (!leftResult.binary || (leftResult.maxNode != nullptr && leftResult.maxNode->val >= root->val)) {
            result.binary = false;
            return result;
        }
        if (leftResult.minNode != nullptr) {
            result.minNode = leftResult.minNode;
        }
        result.sum += leftResult.sum;
        if (!rightResult.binary || (rightResult.minNode != nullptr && rightResult.minNode->val <= root->val)) {
            result.binary = false;
            return result;
        }
        if (rightResult.maxNode != nullptr) {
            result.maxNode = rightResult.maxNode;
        }
        result.sum += rightResult.sum;
        binTreeSum = std::max(binTreeSum, result.sum);
        return result;
    }
public:
    int maxSumBST(TreeNode* root) {
        binTreeSum = 0;
        afterOrder(root);
        return binTreeSum;
    }
};
