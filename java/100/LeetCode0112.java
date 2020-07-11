import util.TreeNode;

public class LeetCode0112 {
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false;
        }
        return pathSum(root, 0, sum);
    }
    private boolean pathSum(TreeNode root, int sum, int target) {
        if (root.left == null && root.right == null) {
            return sum + root.val == target;
        } else if (root.left == null) {
            return pathSum(root.right, sum + root.val, target);
        } else if (root.right == null) {
            return pathSum(root.left, root.val + sum, target);
        } else {
            return pathSum(root.right, sum + root.val, target) || pathSum(root.left, root.val + sum, target);
        }
    }
}