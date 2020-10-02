package L600;

import util.TreeNode;

public class LeetCode0617 {
    /**
     * 考虑两个根节点，
     * 1）存在空结点，返回不空的结点
     * 2）均不空，则将两个节点值相加，返回
     */
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        TreeNode tree = null;
        if (t1 == null && t2 == null){
            tree = null;
        } else if (t1 != null && t2 == null){
            tree = t1;
        } else if (t1 == null && t2 != null){
            tree = t2;
        } else {
            tree = new TreeNode(t1.val + t2.val);
            tree.left = mergeTrees(t1.left, t2.left);
            tree.right = mergeTrees(t1.right, t2.right);
        }
        return tree;
    }
}