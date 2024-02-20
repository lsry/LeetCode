#include "../heads/tree_node.h"
#include <utility>
#include <vector>
using std::vector;

class Solution {
    int findIndex(vector<int> &inorder, int ilow, int iHigh, int value) {
        for (int i = ilow;i <= iHigh;++i) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1;
    }
    std::pair<TreeNode*, int> buildChildTree(vector<int>& preorder, int plow, int phigh, vector<int>& inorder, int ilow, int iHigh) {
        if (plow > phigh || ilow > iHigh) {
            return {nullptr, plow};
        }
        TreeNode *node = new TreeNode(preorder[plow]);
        int id = findIndex(inorder, ilow, iHigh, preorder[plow]);
        auto [ln, p1] = buildChildTree(preorder, plow + 1, phigh, inorder, ilow, id - 1);
        auto [rn, p2] = buildChildTree(preorder, p1, phigh, inorder, id + 1, iHigh);
        node->left = ln;
        node->right = rn;
        return {node, p2};
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pN = preorder.size(), iN = inorder.size();
        auto [node, id] = buildChildTree(preorder, 0, pN - 1, inorder, 0, iN - 1);
        return node;
    }
};