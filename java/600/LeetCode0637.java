import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import util.TreeNode;

public class LeetCode0637 {
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        Queue<TreeNode> qu = new LinkedList<>();
        qu.offer(root);
        while (!qu.isEmpty()) {
            int sz = qu.size();
            long sum = 0;
            for (int i = 0;i < sz;++i) {
                TreeNode n = qu.poll();
                sum += n.val;
                if (n.left != null) {
                    qu.offer(n.left);
                } 
                if (n.right != null) {
                    qu.offer(n.right);
                }
            }
            res.add(1.0 * sum / sz);
        }
        return res;
    }
}
