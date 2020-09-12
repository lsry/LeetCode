package L100;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import util.TreeNode;

public class LeetCode0107 {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new LinkedList<>();
        if (root == null) {
            return res;
        }
        Queue<TreeNode> qu = new LinkedList<>();
        qu.offer(root);
        while (!qu.isEmpty()) {
            int size = qu.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0;i < size;++i) {
                TreeNode cur = qu.poll();
                level.add(cur.val);
                if (cur.left != null) {
                    qu.offer(cur.left);
                }
                if (cur.right != null) {
                    qu.offer(cur.right);
                }
            }
            res.add(0, level);
        }
        return res;
    }
}
