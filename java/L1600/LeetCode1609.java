package L1600;

import java.util.LinkedList;
import java.util.Queue;

import util.TreeNode;

public class LeetCode1609 {
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int level = 0;
        while (!queue.isEmpty()) {
            int sz = queue.size();
            TreeNode last = null;
            for (int i = 0;i < sz;++i) {
                TreeNode cur = queue.poll();
                if (level % 2 == 0) {
                    if ((cur.val % 2 == 0) || (i > 0 && cur.val <= last.val)) {
                        return false;
                    }
                } else if ((cur.val % 2 == 1) || (i > 0 && cur.val >= last.val)) {
                    return false;
                }
                if (cur.left != null) {
                    queue.offer(cur.left);
                }
                if (cur.right != null) {
                    queue.offer(cur.right);
                }
                last = cur;
            }
            ++level;
        }
        return true;
    }
}
