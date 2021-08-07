package L600;

import util.TreeNode;

public class LeetCode0671 {
    Integer[] min = new Integer[2];
    public int findSecondMinimumValue(TreeNode root) {
        if (root.left != null) {
            if (root.left.val > root.right.val) {
                min[0] = root.right.val;
                min[1] = root.left.val;
            } else if (root.left.val < root.right.val) {
                min[0] = root.left.val;
                min[1] = root.right.val;
            } else {
                min[0] = root.left.val;
            }
            helper(root.left);
            helper(root.right);
        }
        return min[1] == null || min[1].compareTo(min[0]) == 0 ? -1 : min[1];
    }

    private void helper(TreeNode root) {
        if (root.left != null) {
            if (root.left.val < min[0]) {
                min[1] = min[0];
                min[0] = root.left.val;
            } else if (root.left.val > min[0] && (min[1] == null || root.left.val < min[1])) {
                min[1] = root.left.val;
            }
            if (root.right.val < min[0]) {
                min[1] = min[0];
                min[0] = root.right.val;
            } else if (root.right.val > min[0] && (min[1] == null || root.right.val < min[1])) {
                min[1] = root.right.val;
            }
            helper(root.left);
            helper(root.right);
        }
    }
}