package L200;

import java.util.ArrayList;
import java.util.List;

import util.TreeNode;

public class LeetCode0257 {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        StringBuilder sb = new StringBuilder();
        sb.append(root.val);
        if (root.left == null && root.right == null) {
            res.add(sb.toString());
            return res;
        } else if (root.left == null) {
            helper(root.right, sb, res);    
        } else if (root.right == null) {
            helper(root.left, sb, res);
        } else {
            helper(root.left, new StringBuilder(sb.toString()), res);
            helper(root.right, sb, res);
        }
        return res;
    }

    private void helper(TreeNode root,StringBuilder sb,List<String> res) {
        if (root == null) {
            res.add(sb.toString());
        } else if (root.left == null && root.right == null) {
            sb.append("->");
            sb.append(root.val);
            res.add(sb.toString());
        } else if (root.right == null) {
            sb.append("->");
            sb.append(root.val);
            helper(root.left, sb, res);
        } else if (root.left == null) {
            sb.append("->");
            sb.append(root.val);
            helper(root.right, sb, res);
        } else {
            sb.append("->");
            sb.append(root.val);
            helper(root.left, new StringBuilder(sb.toString()), res);
            helper(root.right, sb, res);
        }
    }
}
