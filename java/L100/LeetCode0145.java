package L100;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

import util.TreeNode;

public class LeetCode0145 {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Deque<TreeNode> stack = new LinkedList<>();
        TreeNode node = root;
        TreeNode prev = null;
        while (node != null || !stack.isEmpty()) {
            while (node != null) {
                stack.addFirst(node);
                node = node.left;
            }
            node = stack.removeFirst();
            if (node.right == null || node.right == prev) {
                res.add(node.val);
                prev = node;
                node = null;
            } else {
                stack.addFirst(node);
                node = node.right;
            }
        }
        return res;
    }
}
