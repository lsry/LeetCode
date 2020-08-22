package L100;

import util.TreeNode;

public class LeetCode0111 {
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left != null && root.right != null) {
            return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
        }
        if (root.left != null) {
            return minDepth(root.left) + 1;
        }
        if (root.right != null) {
            return minDepth(root.right) + 1;
        }
        return 1;
    }
}