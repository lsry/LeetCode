package L200;

import java.util.Deque;
import java.util.LinkedList;

import util.TreeNode;

public class LeetCode0230 {
    public int kthSmallest(TreeNode root, int k) {
        Deque<TreeNode> stack = new LinkedList<>();
        int i = 1;
        while (!stack.isEmpty() || root != null) {
            while (root != null) {
                stack.addFirst(root);
                root = root.left;
            }
            root = stack.removeFirst();
            if (i == k) {
                return root.val;
            }
            ++i;
            root = root.right;
        }
        return -1;
    }
}
