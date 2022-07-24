#include "heads/tree_node.h"
#include <vector>
#include <queue>

class CBTInserter {
private:
    TreeNode *root_;
    std::vector<TreeNode*> level;
    std::size_t pos;

    void ensurePos() {
        if (pos < level.size()) {
            return;
        }
        std::vector<TreeNode*> nextLevel;
        for (TreeNode *node : level) {
            nextLevel.push_back(node->left);
            nextLevel.push_back(node->right);
        }
        level = nextLevel;
        pos = 0;
    }


public:
    CBTInserter(TreeNode* root):root_(root) {
        level.push_back(root);
        while (true) {
            std::vector<TreeNode*> nextLevel;
            for (std::size_t i{0};i < level.size();++i) {
                TreeNode *node = level[i];
                if (node->left == nullptr || node->right == nullptr) {
                    pos = i;
                    break;
                }
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            }
            if (nextLevel.size() < 2 * level.size()) {
                break;
            } else {
                level = nextLevel;
            }
        }
    }
    
    int insert(int val) {
        ensurePos();
        int pv = level[pos]->val;
        if (level[pos]->left == nullptr) {
            level[pos]->left = new TreeNode(val);
        } else {
            level[pos]->right = new TreeNode(val);
            ++pos;
        }
        return pv;
    }
    
    TreeNode* get_root() {
        return root_;
    }
};