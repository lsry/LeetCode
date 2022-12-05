#include <fast_io.h>
#include <memory>

struct TreeNode {
    std::unique_ptr<TreeNode> left, right;
    int val;
    TreeNode(int val_): val(val_), left(nullptr), right(nullptr) {}
};

int main(int argc, char const *argv[]) {
    std::unique_ptr<TreeNode> root = std::make_unique<TreeNode>(5);
    root->left = std::make_unique<TreeNode>(3);
    root->right = std::make_unique<TreeNode>(7);

    std::unique_ptr<TreeNode> &node = root;
    print(node->val, "(", node->left->val, ", ", node->right->val, ")\n");
    print(root->val, "(", root->left->val, ", ", root->right->val, ")\n");
    return 0;
}
