package L300;

public class LeetCode0343 {
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3;i <= n;++i) {
            int max = 0;
            for (int j = 1;j <= i / 2;++j) {
                max = Math.max(max, j * (i - j));
                max = Math.max(max, j * dp[i - j]);
            }
            dp[i] = max;
        }
        return dp[n];
    }
}