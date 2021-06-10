package L500;

public class LeetCode0518 {
    /**
     * 组合式
     * (k, m) = (k - 1, m) + (k, m - Ck)
     * 排列式：LeetCode0070
     */
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int m = coin;m <= amount;++m) {
                dp[m] += dp[m - coin];
            }
        }
        return dp[amount];
    }
}
