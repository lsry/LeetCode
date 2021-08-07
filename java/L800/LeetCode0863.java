package L800;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

import util.TreeNode;

public class LeetCode0863 {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<TreeNode> parents = new ArrayList<>();
        getParents(root, target, parents);
        int k1 = k, sz = parents.size();
        List<Integer> res = new ArrayList<>();
        for (int i = 0;i < sz && k1 >= 0;++i, --k1) {
            if (i == 0) {
                bfs(parents.get(i), k1, res, null);
            } else {
                bfs(parents.get(i), k1, res, parents.get(i - 1));
            }
        }
        return res;
    }

    private void bfs(TreeNode node, int k, List<Integer> res, TreeNode child) {
        if (k == 0) {
            res.add(node.val);
            return;
        }
        Deque<TreeNode> qu = new LinkedList<>();
        if (child == null) {
            qu.offer(node);
        } else {
            if (node.left != null && node.left.val != child.val) {
                qu.offer(node.left);
            } else if (node.right != null && node.right.val != child.val) {
                qu.offer(node.right);
            }
            --k;
        }
        while (!qu.isEmpty()) {
            if (k == 0) {
                while (!qu.isEmpty()) {
                    res.add(qu.poll().val);
                }
                break;
            }
            int sz = qu.size();
            for (int i = 0;i < sz;++i) {
                TreeNode cur = qu.poll();
                if (cur.left != null) {
                    qu.offer(cur.left);
                }
                if (cur.right != null) {
                    qu.offer(cur.right);
                }
            }
            --k;
        }
    }

    private boolean getParents(TreeNode root, TreeNode target, List<TreeNode> parents) {
        if (root == null) {
            return false;
        }
        if (root.val == target.val) {
            parents.add(root);
            return true;
        }
        if (getParents(root.left, target, parents) || getParents(root.right, target, parents)) {
            parents.add(root);
            return true;
        }
        return false;
    }
}
