package L100;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import util.TreeNode;

public class LeetCode0199 {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Queue<TreeNode> cur = new LinkedList<>();
        if (root != null) {
            cur.offer(root);
        }
        while (!cur.isEmpty()) {
            Queue<TreeNode> temp = new LinkedList<>();
            int value = 0;
            // 可以先得出当前队列元素个数，即为当前层，然后遍历该层，记录最后一个结点元素值
            do {
                TreeNode node = cur.poll();
                value = node.val;
                if (node.left != null) {
                    temp.offer(node.left);
                }
                if (node.right != null) {
                    temp.offer(node.right);
                }
            } while (!cur.isEmpty());
            res.add(value);
            cur = temp;
        }
        return res;
    }
}