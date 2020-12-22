package L100;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import util.TreeNode;

public class LeetCode0103 {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean left = true;
        while (!queue.isEmpty()) {
            int sz = queue.size();
            LinkedList<Integer> leveList = new LinkedList<>();
            if (left) {
                for (int i = 0;i < sz;++i) {
                    TreeNode cur = queue.poll();
                    leveList.add(cur.val);
                    if (cur.left != null) {
                        queue.add(cur.left);
                    }
                    if (cur.right != null) {
                        queue.add(cur.right);
                    }
                }
            } else {
                for (int i = 0;i < sz;++i) {
                    TreeNode cur = queue.poll();
                    leveList.addFirst(cur.val);
                    if (cur.left != null) {
                        queue.add(cur.left);
                    }
                    if (cur.right != null) {
                        queue.add(cur.right);
                    }
                }
            }
            res.add(leveList);
            left = !left;
        }
        return res;
    }
}
