package L900;

import java.util.Deque;
import java.util.LinkedList;

import util.TreeNode;

public class LeetCode0993 {
    public boolean isCousins(TreeNode root, int x, int y) {
        if (root == null) {
            return false;
        }
        Deque<TreeNode> qu = new LinkedList<>();
        qu.offer(root);
        while (!qu.isEmpty()) {
            int sz = qu.size();
            int[] flags = new int[]{-1, -1};
            for (int i = 0;i < sz;++i) {
                TreeNode node = qu.poll();
                if (node.left != null) {
                    if (node.left.val == x) {
                        if (flags[1] != -1 && flags[1] != i) {
                            return true;
                        }
                        if (flags[0] == -1) {
                            flags[0] = i;
                        }
                    } else if (node.left.val == y) {
                        if (flags[0] != -1 && flags[0] != i) {
                            return true;
                        }
                        if (flags[1] == -1) {
                            flags[1] = i;
                        }
                    }
                    qu.offer(node.left);
                }
                if (node.right != null) {
                    if (node.right.val == x) {
                        if (flags[1] != -1 && flags[1] != i) {
                            return true;
                        }
                        if (flags[0] == -1) {
                            flags[0] = i;
                        }
                    } else if (node.right.val == y) {
                        if (flags[0] != -1 && flags[0] != i) {
                            return true;
                        }
                        if (flags[1] == -1) {
                            flags[1] = i;
                        }
                    }
                    qu.offer(node.right);
                }
            }
        }
        return false;
    }
}
