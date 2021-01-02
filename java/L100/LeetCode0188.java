package L100;

public class LeetCode0188 {
    public int maxProfit(int k, int[] prices) {
        if (prices == null || prices.length < 2) {
            return 0;
        }
        final int N = prices.length;
        int[][][] profits = new int[N][N / 2 + 1][2];
        profits[0][0][0] = 0 - prices[0];
        for (int i = 1;i < N / 2 + 1;++i) {
            profits[0][i][0] = Integer.MIN_VALUE / 2;
            profits[0][i][1] = Integer.MIN_VALUE / 2;
        }
        for (int i = 1;i < N;++i) {
            profits[i][0][0] = Math.max(profits[i - 1][0][0], profits[i - 1][0][1] - prices[i]);
            for (int j = 1;j < N / 2 + 1;++j) {
                profits[i][j][0] = Math.max(profits[i - 1][j][1] - prices[i], profits[i - 1][j][0]);
                profits[i][j][1] = Math.max(profits[i - 1][j - 1][0] + prices[i], profits[i - 1][j][1]);
            }
        }
        int ans = 0;
        k = Math.min(k, N / 2);
        for (int i = 0;i <= k;++i) {
            ans = Math.max(ans, profits[N - 1][i][1]);
        }
        return ans;
    }
}
