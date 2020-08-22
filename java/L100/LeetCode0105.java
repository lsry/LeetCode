package L100;

import util.TreeNode;

public class LeetCode0105 {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0) {
            return null;
        }
        return help(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }
    public TreeNode help(int[] preorder,int pi, int pj, int[] inorder, int ii, int ij) {
        if (pi > pj) {
            return null;
        }
        TreeNode cur = new TreeNode(preorder[pi]);
        if (pi == pj) {
            return cur;
        }
        int iroot = ii;
        for (;iroot <= ij;++iroot) {
            if (inorder[iroot] == preorder[pi]) {
                break;
            }
        }
        TreeNode left = help(preorder, pi + 1, pi + iroot - ii, inorder, ii, iroot - 1);
        TreeNode right = help(preorder, pi + iroot - ii + 1, pj, inorder, iroot + 1, ij);
        cur.left = left;
        cur.right = right;
        return cur;
    }
}