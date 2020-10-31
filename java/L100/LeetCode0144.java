package L100;

import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

import util.TreeNode;

public class LeetCode0144 {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        Deque<TreeNode> stack = new LinkedList<>();
        stack.add(root);
        while (!stack.isEmpty()) {
            TreeNode cur = stack.removeFirst();
            if (cur.right != null) {
                stack.addFirst(cur.right);
            }
            if (cur.left != null) {
                stack.addFirst(cur.left);
            }
            res.add(cur.val);
        }
        return res;

    }
}
