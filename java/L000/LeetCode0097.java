package L000;

public class LeetCode0097 {
    /**
     * key: 如果能交错而成，则前两个字符串长度之和等于第三个字符串长度
     */
    public boolean isInterleave(String s1, String s2, String s3) {
        final int N1 = s1.length(), N2 = s2.length(), N3 = s3.length();
        if (N1 + N2 != N3) {
            return false;
        }
        boolean[][] dp = new boolean[N1 + 1][N2 + 1];
        dp[0][0] = true;
        for (int i = 1;i <= N2;++i) {
            if (s2.charAt(i - 1) != s3.charAt(i - 1)) {
                break;
            }
            dp[0][i] = true;
        }
        for (int i = 1;i <= N1;++i) {
            if (s1.charAt(i - 1) != s3.charAt(i - 1)) {
                break;
            }
            dp[i][0] = true;
        }
        for (int i = 1;i <= N1;++i) {
            for (int j = 1;j <= N2;++j) {
                dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) ||
                           (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
            }
        }
        return dp[N1][N2];
    }
}