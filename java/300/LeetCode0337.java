import util.TreeNode;

public class LeetCode0337 {
    
    public int robBrutce(TreeNode root) {
        return Math.max(treeSum2(root, true),treeSum2(root, false));
    }

    /**
     * Runtime: 1084 ms, faster than 5.01% 
     */
    private int treeSum2(TreeNode root,boolean selected) {
        if (root == null) {
            return 0;
        } else if (selected) {
            return root.val + treeSum2(root.left, !selected) + treeSum2(root.right, !selected);
        } else {
            return robBrutce(root.left) + robBrutce(root.right);
        } 
    }

    /**
     * 940ms 5.01% 
     */
    public int treeSum(TreeNode root,boolean selected) {
        if (root == null) {
            return 0;
        } else if (selected) {
            return root.val + treeSum(root.left, !selected) + treeSum(root.right, !selected);
        } else {
            int lefts = treeSum(root.left, true);
            int leftn = treeSum(root.left, false);
            int rights = treeSum(root.right, true);
            int rightn = treeSum(root.right, false);
            return Math.max(lefts, leftn) + Math.max(rights, rightn);
        } 
    }

    /**
     * dynamic program
     * 对任何一个结点，均可以偷或者不偷
     * 1）不偷，则等于左子节点最大值和右子节点最大值之和
     * 2）偷，则等于该结点值和不偷左右结点值之和
     */
    public int rob(TreeNode root) {
        int[] res = robbed(root);
        return Math.max(res[0], res[1]);
    }

    public int[] robbed(TreeNode root) {
        if (root == null) {
            return new int[]{0,0};
        }
        int[] lv = robbed(root.left);
        int[] rv = robbed(root.right);
        return new int[]{root.val + lv[1] + rv[1],Math.max(lv[0], lv[1]) + Math.max(rv[0], rv[1])};
    }
}