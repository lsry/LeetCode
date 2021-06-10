package L800;

public class LeetCode0879 {
    private static final long MOD = 1_000_000_007;
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        long[][] dp = new long[n + 1][minProfit + 1];
        final int N = group.length;
        for (int i = 0;i <= n;++i) {
            dp[i][0] = 1;
        }
        for (int i = 0;i < N;++i) {
            for (int j = n;j - group[i] >= 0;--j) {
                for (int k = minProfit;k >= 0;--k) {
                    if (k - profit[i] >= 0) {
                        dp[j][k] = (dp[j][k] + dp[j - group[i]][k - profit[i]]) % MOD;
                    } else {
                        dp[j][k] = (dp[j][k] + dp[j - group[i]][0]) % MOD;
                    }
                }
            }
        }
        return (int)dp[n][minProfit];
    }
}
