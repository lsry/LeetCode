package L900;

import util.TreeNode;

public class LeetCode0968 {
    public int minCameraCover(TreeNode root) {
        return dfs(root)[1];
    }
    private int[] dfs(TreeNode node) {
        if (node == null) {
            return new int[]{Integer.MAX_VALUE / 2, 0, 0};
        }
        int[] lvs = dfs(node.left);
        int[] rvs = dfs(node.right);
        int[] res = new int[3];
        // 考虑求三种状态当前最小值
        res[0] = lvs[2] + rvs[2] + 1;
        res[1] = Math.min(res[0], Math.min(lvs[0] + rvs[1], lvs[1] + rvs[0]));
        res[2] = Math.min(res[0], lvs[1] + rvs[1]);
        return res;
    }
}
