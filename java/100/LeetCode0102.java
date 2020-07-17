import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import util.TreeNode;

public class LeetCode0102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        Queue<TreeNode> level = new LinkedList<>();
        if (root != null) {
            level.offer(root);
        }
        while (!level.isEmpty()) {
            int size = level.size();
            List<Integer> li = new ArrayList<>();
            for (int i = 0;i < size;++i) {
                TreeNode cur = level.poll();
                li.add(cur.val);
                if (cur.left != null) {
                    level.offer(cur.left);
                }
                if (cur.right != null) {
                    level.offer(cur.right);
                }
            }
            res.add(li);
        }
        return res;
    }
}