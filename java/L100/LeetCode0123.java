package L100;

public class LeetCode0123 {
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2) {
            return 0;
        }
        final int N = prices.length;
        int[][][] dp = new int[N][3][2];
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < 3;++j) {
                for (int k = 0;k < 2;++k) {
                    dp[i][j][k] = -1000_000;
                }
            }
        }
        dp[0][0][0] = -prices[0]; // 0: 持有股票
        dp[0][0][1] = 0;
        for (int i = 1;i < N;++i) {
            dp[i][0][0] = Math.max(dp[i - 1][0][0], dp[i - 1][0][1] - prices[i]);
            dp[i][0][1] = dp[i - 1][0][1];
            dp[i][1][0] = Math.max(dp[i - 1][1][0], dp[i - 1][1][1] - prices[i]);
            dp[i][1][1] = Math.max(dp[i - 1][1][1], dp[i - 1][0][0] + prices[i]);
            dp[i][2][0] = Math.max(dp[i - 1][2][0], dp[i - 1][2][1] - prices[i]);
            dp[i][2][1] = Math.max(dp[i - 1][2][1], dp[i - 1][1][0] + prices[i]);
        }
        int max = 0;
        for (int i = 0;i < 3;++i) {
            for (int j = 0;j < 2;++j) {
                max = Math.max(max, dp[N - 1][i][j]);
            }
        }
        return max;
    }
}
