#include <string>
using std::string;

#include <queue>
using std::queue;

#include "../heads/tree_node.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string res{std::to_string(root->val)};
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode *node = qu.front();
            qu.pop();
            if (node->left != nullptr && node->right != nullptr) {
                res += "," + std::to_string(node->left->val);
                res += "," + std::to_string(node->right->val);
                qu.push(node->left);
                qu.push(node->right);
            } else if (node->left != nullptr) {
                res += "," + std::to_string(node->left->val);
                qu.push(node->left);
                res += ",null";
            } else if (node->right != nullptr) {
                res += ",null," + std::to_string(node->right->val);
                qu.push(node->right);
            } else {
                res += ",null,null";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::size_t sz{data.size()};
        queue<TreeNode*> qu;
        TreeNode *root = nullptr;
        for (std::size_t i{0};i < sz;++i) {
            if (data[i] == ',') {
                continue;
            }
            if (root == nullptr) {
                TreeNode *cur = constructChild(data, i);
                root = cur;
                qu.push(cur);
            } else {
                TreeNode *cur = qu.front();
                qu.pop();
                TreeNode *ln = constructChild(data, i);
                ++i;
                TreeNode *rn = constructChild(data, i);
                if (ln != nullptr) {
                    cur->left = ln;
                    qu.push(ln);
                }
                if (rn != nullptr) {
                    cur->right = rn;
                    qu.push(rn);
                }
            }
        }
        return root;
    }

    TreeNode* constructChild(string const &data, std::size_t &i) {
        std::size_t sz{data.size()};
        if (i >= sz) {
            return nullptr;
        }
        if (data[i] == 'n') {
            i = i + 4;
            return nullptr;
        }
        int num = 0;
        while (i < sz && data[i] != ',') {
            num = num * 10 + (data[i] - '0');
            ++i;
        }
        TreeNode *node = new TreeNode(num);
        return node;
    }
};