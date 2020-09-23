package L200;

import util.TreeNode;

public class LeetCode0226 {
    public TreeNode invertTree(TreeNode root) {
        if (root != null) {
            TreeNode ln = invertTree(root.left);
            TreeNode rn = invertTree(root.right);
            root.left = rn;
            root.right = ln;
        }
        return root;
    }
}
