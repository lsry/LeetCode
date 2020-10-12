package L500;

import util.TreeNode;

public class LeetCode0530 {
    private int minDiffer = Integer.MAX_VALUE;
    private TreeNode last = null;
    public int getMinimumDifference(TreeNode root) {
        inorder(root);
        return minDiffer;
    }

    private void inorder(TreeNode cur) {
        if (cur != null) {
            inorder(cur.left);
            if (last == null) {
                last = cur;
            } else {
                minDiffer = Math.min(minDiffer, Math.abs(cur.val - last.val));
                last = cur;
            }
            inorder(cur.right);
        }
    }
}
