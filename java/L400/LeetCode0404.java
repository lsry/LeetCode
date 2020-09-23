package L400;

import util.TreeNode;

public class LeetCode0404 {
    private static final boolean LEFT = false;
    private static final boolean RIGHT = true;
    public int sumOfLeftLeaves(TreeNode root) {
        return dfs(root, RIGHT);
    }
    private int dfs(TreeNode root, boolean dire) {
        if (root == null) {
            return 0;
        }
        if (root.left == null && root.right == null) {
            return dire == LEFT ? root.val : 0;
        }
        return dfs(root.left, LEFT) + dfs(root.right, RIGHT);
    }
}
