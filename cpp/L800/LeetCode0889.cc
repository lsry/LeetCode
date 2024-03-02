#include <vector>
using std::vector;
#include "../heads/tree_node.h"

class Solution {
    int findIndex(vector<int> &inorder, int ilow, int iHigh, int value) {
        for (int i = ilow;i <= iHigh;++i) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* buildChildTree(vector<int> &preorder, int plow, int phigh, vector<int> &postorder, int low, int high) {
        if (plow > phigh || low > high) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[plow]);
        if (plow + 1 > phigh) {
            return node;
        }
        int id = findIndex(postorder, low, high, preorder[plow + 1]);
        int ln = id - low + 1, rn = high - id - 1;
        node->left = buildChildTree(preorder, plow + 1, plow + ln, postorder, low, id);
        node->right = buildChildTree(preorder, plow + ln + 1, phigh, postorder, id + 1, high - 1);
        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int prN = preorder.size(), poN = postorder.size();
        return buildChildTree(preorder, 0, prN - 1, postorder, 0, poN - 1);
    }
};