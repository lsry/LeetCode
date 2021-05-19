package L1200;

public class LeetCode1269 {
    private static final int MOD = 1_000_000_007;
    public int numWays(int steps, int arrLen) {
        int MN = Math.min(steps + 1, arrLen);
        int[][] dp = new int[MN][steps + 1];
        dp[0][0] = dp[0][1] = 1;
        for (int i = 2;i <= steps;++i) {
            dp[0][i] = (trace(0, i, dp) + 1) % MOD;
        }
        return dp[0][steps];
    }

    private int trace(int pos, int steps, int[][] dp) {
        if (pos < 0 || pos > steps || pos >= dp.length) {
            return 0;
        }
        if (dp[pos][steps] == 0) {
            long x = 0;
            for (int i = 0;i <= steps;++i) {
                x += (trace(pos - 1, steps - 1 - i, dp) % MOD + trace(pos + 1, steps - 1 - i, dp) % MOD) % MOD;
            }
            dp[pos][steps] = (int)(x % MOD);
        }
        return dp[pos][steps];
    }
}
