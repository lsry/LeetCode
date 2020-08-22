package L100;

import util.TreeNode;

public class LeetCode0110 {
    class Res {
        public int height;
        public boolean balance;
        public Res(int h,boolean b) {
            height = h;
            balance = b;
        }
    }
    public boolean isBalanced(TreeNode root) {
        return judge(root).balance;
    }
    private Res judge(TreeNode root) {
        if (root == null) {
            return new Res(0,true);
        }
        Res lr = judge(root.left);
        Res rr = judge(root.right);
        if (!lr.balance || !rr.balance || Math.abs(lr.height - rr.height) > 1) {
            return new Res(1+Math.max(lr.height, rr.height),false);
        } else {
            return new Res(1+Math.max(lr.height, rr.height),true);
        }
    }
}