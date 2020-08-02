import java.util.Deque;
import java.util.LinkedList;
import util.TreeNode;

public class LeetCode0114 {
    public void flatten(TreeNode root) {
        if (root == null) {
            return;
        }
        TreeNode head = new TreeNode(3);
        TreeNode tail = head;
        Deque<TreeNode> stack = new LinkedList<>();
        stack.addFirst(root);
        while (!stack.isEmpty()) {
            TreeNode cur = stack.removeFirst();
            if (cur.right != null) {
                stack.addFirst(cur.right);
                cur.right = null;
            }
            if (cur.left != null) {
                TreeNode ln = cur.left;
                cur.left = null;
                cur.right = ln;
                stack.addFirst(ln);
            }
            tail.right = cur;
            tail = cur;
        }
        root = head.right;
    }
}