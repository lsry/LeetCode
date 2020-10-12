package L700;

import util.TreeNode;

public class LeetCode0701 {
    public TreeNode insertIntoBST(TreeNode root, int val) {       
        TreeNode parent = null;
        TreeNode cNode = root;
        while (cNode != null) {
            parent = cNode;
            if (cNode.val > val) {
                cNode = cNode.left;
            } else {
                cNode = cNode.right;
            }
        }
        TreeNode node = new TreeNode(val);
        if (parent == null) {
            return node;
        }
        if (parent.val > val) {
            parent.left = node;
        } else {
            parent.right = node;
        }
        return root;
    }
}
