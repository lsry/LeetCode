package L200;

import util.TreeNode;

public class LeetCode0222 {
    public int countNodes(TreeNode root) {
        int count = 0;
        while (root != null) {
            count += 1;
            int lh = getHeight(root.left);
            int rh = getHeight(root.right);
            if (lh == rh) {
                count += (1 << lh) - 1;
                root = root.right;
            } else {
                count += (1 << rh) - 1;
                root = root.left;
            }
        }
        return count;
    }

    private int getHeight(TreeNode root) {
        int height = 0;
        while (root != null) {
            ++height;
            root = root.left;
        }
        return height;
    }
}
