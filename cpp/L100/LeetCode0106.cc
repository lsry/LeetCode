#include "../heads/tree_node.h"
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
    TreeNode* buildChildTree(vector<int> &inorder, int ilow, int iHigh, vector<int> &postorder, int plow, int phigh) {
        if (ilow > iHigh || plow > phigh) {
            return nullptr;
        }
        TreeNode *node = new TreeNode(postorder[phigh]);
        int id = findIndex(inorder, ilow, iHigh, postorder[phigh]);
        int lz = id - ilow, rz = iHigh - id;
        node->left = buildChildTree(inorder, ilow, id - 1, postorder, plow, plow + lz - 1);
        node->right = buildChildTree(inorder, id + 1, iHigh, postorder, plow + lz, phigh - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int iz = inorder.size(), pz = postorder.size();
        return buildChildTree(inorder, 0, iz - 1, postorder, 0, pz - 1);
    }
};