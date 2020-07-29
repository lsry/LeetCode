import java.util.Arrays;

public class LeetCode0065 {
    public int minPathSum(int[][] grid) {
        if (grid.length == 0) {
            return 0;
        }
        int[] dp = new int[grid[0].length];
        dp[0] = grid[0][0];
        for (int i = 1;i < grid[0].length;++i) {
            dp[i] = grid[0][i] + dp[i - 1];
        }
        for (int i = 1;i < grid.length;++i) {
            for (int j = 0;j < grid[0].length;++j) {
                int left = j - 1 >= 0 ? dp[j - 1] : Integer.MAX_VALUE;
                int top = dp[j];
                dp[j] = grid[i][j] + Math.min(left, top);
            }
        }
        return dp[dp.length - 1];
    }
}