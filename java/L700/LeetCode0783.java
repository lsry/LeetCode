package L700;

import java.util.Deque;
import java.util.LinkedList;

import util.TreeNode;

public class LeetCode0783 {
    public int minDiffInBST(TreeNode root) {
        Deque<TreeNode> stack = new LinkedList<>();
        TreeNode before = null;
        int min_diff = Integer.MAX_VALUE;
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.addFirst(root);
                root = root.left;
            }
            root = stack.removeFirst();
            if (before != null) {
                min_diff = Math.min(min_diff, root.val - before.val);
            }
            before = root;
            root = root.right;
        }
        return min_diff;
    }
}
