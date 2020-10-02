package L100;

import util.TreeNode;

public class LeetCode0106 {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return build(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }
    private TreeNode build(int[] inorder,int il,int ir,int[] postorder,int pl,int pr) {
        if (il > ir || pl > pr) {
            return null;
        } else if (il == ir) {
            return new TreeNode(inorder[il]);
        }
        TreeNode node = new TreeNode(postorder[pr]);
        int ri = il;
        for (int i = il;i <= ir;++i) {
            if (inorder[i] == postorder[pr]) {
                ri = i;
                break;
            }
        }
        int pi = pl + ri - il - 1;
        node.left = build(inorder, il, ri - 1, postorder, pl, pi);
        node.right = build(inorder, ri + 1, ir, postorder, pi + 1, pr - 1);
        return node;
    }
}