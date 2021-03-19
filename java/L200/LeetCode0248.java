package L200;

public class LeetCode0248 {
    public int numDistinct(String s, String t) {
        final int SN = s.length(), TN = t.length();
        if (TN > SN) {
            return 0;
        }
        int[][] dp = new int[SN + 1][TN + 1];
        for (int i = 0;i <= SN;++i) {
            dp[i][TN] = 1;
        }
        for (int i = TN - 1;i >= 0;--i) {
            for (int j = SN - 1;j >= 0;--j) {
                if (s.charAt(j) == t.charAt(i)) {
                    dp[j][i] = dp[j + 1][i + 1] + dp[j + 1][i];
                } else {
                    dp[j][i] = dp[j + 1][i];
                }
            }
        }
        return dp[0][0];
    }
}
