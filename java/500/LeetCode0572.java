public class LeetCode0572 {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if (t == null) {
            return true;
        } else if (s == null) {
            return false;
        } else if (s.val == t.val && isSame(s, t)) {
            return true;
        } else {
            return isSubtree(s.left, t) || isSubtree(s.right, t);
        }
    }

    private boolean isSame(TreeNode t1,TreeNode t2) {
        if (t1 == null && t2 == null) {
            return true;
        } else if (t1 != null && t2 != null) {
            return t1.val == t2.val && isSame(t1.left, t2.left) && isSame(t1.right, t2.right);
        } else {
            return false;
        }
    }
}