package L100;

import util.TreeNode;

public class LeetCode0129 {
    private int total;
    public int sumNumbers(TreeNode root) {
        total = 0;
        pathNum(0, root);
        return total;
    }

    private void pathNum(int last, TreeNode root) {
        if (root == null) {
            return;
        }
        if (root.left == null && root.right == null) {
            total += last * 10 + root.val;
        } else if (root.left == null) {
            pathNum(last * 10 + root.val, root.right);
        } else if (root.right == null) {
            pathNum(last * 10 + root.val, root.left);
        } else {
            pathNum(last * 10 + root.val, root.left);
            pathNum(last * 10 + root.val, root.right);
        }
    }
}
