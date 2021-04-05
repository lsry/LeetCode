package L1100;

public class LeetCode1143 {
    public int longestCommonSubsequence(String text1, String text2) {
        if (text1 == null || text2 == null) {
            return 0;
        }
        final int M = text1.length(), N = text2.length();
        if (M == 0 || N == 0) {
            return 0;
        }
        int[][] dp = new int[N + 1][M + 1];
        for (int i = 1;i <= N;++i) {  // text2
            for (int j = 1;j <= M;++j) {  // text1
                if (text1.charAt(j - 1) == text2.charAt(i - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[N][M];
    }
}
