#include "heads/tree_node.h"
#include <vector>
using std::vector;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return binConstruct(nums, 0, nums.size() - 1);
    }

    TreeNode* binConstruct(vector<int> &nums, int low, int high) {
        if (high < low) {
            return nullptr;
        }
        if (low == high) {
            return new TreeNode(nums[low]);
        }
        int mi = low;
        for (int i = low + 1;i <= high;++i) {
            if (nums[i] > nums[mi]) {
                mi = i;
            }
        }
        TreeNode *node = new TreeNode(nums[mi]);
        node->left = binConstruct(nums, low, mi - 1);
        node->right = binConstruct(nums, mi + 1, high);
        return node;
    }
};