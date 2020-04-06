public class LeetCode0072 {
    public int minDistance(String word1, String word2) {
        int L1 = word1.length();
        int L2 = word2.length();
        if (L1 * L2 == 0) {
            return Math.max(L1, L2);
        }
        int[][] dp = new int[L1 + 1][L2 + 1];
        for (int i = 0;i <= L1;i++) {
            dp[i][0] = i;
        }
        for (int j = 0;j <= L2;++j) {
            dp[0][j] = j;
        }
        for (int i = 1;i <= L1;++i) {
            for (int j = 1;j <= L2;++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] - 1) + 1;
                } else {
                    dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[L1][L2];
    }
}