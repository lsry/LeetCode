import util.TreeNode;

public class LeetCode0124 {
    private int sum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        pathSum(root);
        return sum;
    }

    public Integer pathSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int lv = Math.max(0, pathSum(root.left));
        int rv = Math.max(0, pathSum(root.right));
        sum = Math.max(sum, root.val + lv + rv);
        return Math.max(root.val + lv, root.val + rv);
    }
}