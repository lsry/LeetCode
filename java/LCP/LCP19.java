package LCP;

public class LCP19 {
    public int minimumOperations(String leaves) {
        final int N = leaves.length();
        int[][] dp = new int[N][3];
        dp[0][0] = leaves.charAt(0) == 'y' ? 1 : 0;
        dp[0][1] = dp[0][2] = Integer.MAX_VALUE;
        for (int i = 1;i < N;++i) {
            char color = leaves.charAt(i);
            dp[i][0] = dp[i - 1][0] + (color == 'y' ? 1 : 0);
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][1]) + (color == 'r' ? 1 : 0);
            dp[i][2] = Math.min(dp[i - 1][1], dp[i - 1][2]) + (color == 'y' ? 1 : 0);
        }
        return dp[N - 1][2];
    }
}
