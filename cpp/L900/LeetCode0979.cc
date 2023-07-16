#include "../heads/tree_node.h"

class Solution {
    int ans{0};

    // 当本节点有多余的硬币，优先供给子树，再向上推送
    int postOrder(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int ln = postOrder(root->left);
        int rn = postOrder(root->right);
        if (ln > 0) {
            ans += ln;
            if (root->val == 0) {
                ln--;
                root->val = 1;
            }
        }
        if (rn > 0) {
            ans += rn;
            if (root->val == 0) {
                rn--;
                root->val = 1;
            }
        }
        int r{0};
        if (root->val > 1) {
            r += root->val - 1;
            root->val = 1;
        } 
        if (ln > 0) {
            r += ln;
        }
        if (rn > 0) {
            r += rn;
        }
        if (r > 0 && root->val == 0) {
            r -= 1;
            root->val = 1;
        }
        if (ln < 0 && r > 0) {
            preOrder(root->left, 1, r + ln >= 0 ? -ln : r);
            if (r + ln >= 0) {
                r += ln;
                ln = 0;
            } else {
                ln += r;
                r = 0;
            }
        }
        if (rn < 0 && r > 0) {
            preOrder(root->right, 1, r + rn >= 0 ? -rn : r);
            if (r + rn >= 0) {
                r += rn;
                rn = 0;
            } else {
                rn += r;
                r = 0;
            }
        }
        if (r > 0) {
            return r;
        }
        r = 0;
        if (root->val == 0) {
            r -= 1;
        }
        if (ln < 0) {
            r += ln;
        }
        if (rn < 0) {
            r += rn;
        }
        return r;
    }

    int preOrder(TreeNode *root, int level, int coins) {
        if (root == nullptr || coins == 0) {
            return coins;
        }
        if (root->val == 0) {
            root->val = 1;
            ans += level;
            --coins;
        }
        int leftCoin = preOrder(root->left, level + 1, coins);
        int rightCoin = preOrder(root->right, level + 1, leftCoin);
        return rightCoin;
    }
public:
    int distributeCoins(TreeNode* root) {
        ans = 0;
        int n = postOrder(root);
        preOrder(root, 0, n);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    TreeNode *t1 = new TreeNode(0), *t2 = new TreeNode(0);
    TreeNode *t3 = new TreeNode(0), *t4 = new TreeNode(0);
    t3->right = t1;
    t4->right = t2;
    TreeNode *t5 = new TreeNode(7);
    t5->left = t3;
    t5->right = t4;
    TreeNode *t6 = new TreeNode(0);
    TreeNode *t7 = new TreeNode(0);
    t7->left = t6;
    t7->right = t5;
    Solution s;
    s.distributeCoins(t7);
    return 0;
}
