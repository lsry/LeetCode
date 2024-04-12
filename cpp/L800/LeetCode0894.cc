#include "../heads/tree_node.h"
#include <vector>
using std::vector;

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }
        if (n == 1) {
            return {new TreeNode(0)};
        }
        vector<TreeNode*> r;
        for (int i = 1;i < n;i += 2) {
            vector<TreeNode*> lns = allPossibleFBT(i);
            vector<TreeNode*> rns = allPossibleFBT(n - i - 1);
            for (TreeNode *ln : lns) {
                for (TreeNode *rn : rns) {
                    TreeNode * h = new TreeNode(0, ln, rn);
                    r.push_back(h);
                }
            }
        }
        return r;
    }
};