import util.TreeNode;
public class LeetCode0101 {
    public boolean isSymmetric(TreeNode root) {
        return root == null || childTree(root.left, root.right);
    }

    public boolean childTree(TreeNode left,TreeNode right) {
        if (left == null && right == null) {
            return true;
        } else if (left == null || right == null) {
            return false;
        }
        return left.val == right.val && childTree(left.left, right.right) && childTree(left.right, right.left);

    }
}