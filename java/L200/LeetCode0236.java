package L200;

import util.TreeNode;

public class LeetCode0236 {
    public TreeNode lowestCommonAncestor10ms(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null){
            return null;
        } else if (root == p){
            return find(p, q)? p : null;
        } else if (root == q){
            return find(q, p) ? q : null;
        }
        TreeNode node = lowestCommonAncestor10ms(root.left, p, q);
        if (node != null){
            return node;
        }
        node = lowestCommonAncestor10ms(root.right, p, q);
        if (node != null){
            return node;
        }
        if (find(root.left, p) && find(root.right, q) || find(root.left, q) && find(root.right, p)){
            return root;
        } else {
            return null;
        }
    }

    public boolean find(TreeNode root, TreeNode n){
        TreeNode x = root;
        if (x == null){
            return false;
        } else if (x == n) {
            return true;
        } else {
            return find(x.left, n) || find(x.right, n);
        }
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) {
            return root;
        } else if (left != null) {
            return left;
        } else if (right != null) {
            return right;
        } else {
            return null;
        }
    }
}