package L300;

import java.util.Arrays;

public class LeetCode0375 {
    public int getMoneyAmount(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
            dp[i][i] = 0;
        }
        dfs(dp, 1, n);
        return dp[1][n];
    }

    private void dfs(int[][] dp, int i, int j) {
        if (i >= j) return;
        if (dp[i][j] != Integer.MAX_VALUE) return;
        if (i + 1 == j) {
            dp[i][j] = i;
            return;
        }
        for (int k = i + 1; k < j; k++) {
            dfs(dp, i, k - 1);
            dfs(dp, k + 1, j);
            dp[i][j] = Math.min(dp[i][j], Math.max(dp[i][k - 1], dp[k + 1][j]) + k);
        }
    }
}