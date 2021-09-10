package L500;

public class LeetCode0552 {
    private static final int MOD = 1_000_000_007;
    public int checkRecord(int n) {
        long[][][] dp = new long[n + 1][2][3];
        dp[0][0][0] = 1;
        for (int i = 1;i <= n;++i) {
            // P
            for (int A = 0;A < 2;++A) {
                for (int L = 0;L < 3;++L) {
                    dp[i][A][0] = (dp[i - 1][A][L] + dp[i][A][0]) % MOD;
                }
            }
            // A
            for (int L = 0;L < 3;++L) {
                dp[i][1][0] = (dp[i - 1][0][L] + dp[i][1][0]) % MOD;
            }
            // L
            for (int L = 1;L < 3;++L) {
                for (int A = 0;A < 2;++A) {
                    dp[i][A][L] = (dp[i - 1][A][L - 1] + dp[i][A][L]) % MOD;
                }
            }
        }
        long ans = 0;
        for (int A = 0;A < 2;++A) {
            for (int L = 0;L < 3;++L) {
                ans = (ans + dp[n][A][L]) % MOD;
            }
        }
        return (int)ans;
    }
}