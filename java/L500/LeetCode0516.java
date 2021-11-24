package L500;

import java.util.Arrays;

public class LeetCode0516 {
    public int longestPalindromeSubseq(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        final int N = s.length();
        int[][] dp = new int[N][N];
        for (int i = 0;i < N;++i) {
            Arrays.fill(dp[i], -1);
            dp[i][i] = 1;
        }
        char[] chars = s.toCharArray();
        return range(chars, 0, N - 1, dp);
    }

    private int range(char[] chars, int low, int high, int[][] dp) {
        if (low > high) {
            return 0;
        }
        if (dp[low][high] >= 0) {
            return dp[low][high];
        }
        if (chars[low] == chars[high]) {
            dp[low][high] = range(chars, low + 1, high - 1, dp) + 2;
            return dp[low][high];
        }
        dp[low][high] = Math.max(range(chars, low, high - 1, dp), range(chars, low + 1, high, dp));
        return dp[low][high];
    }
}
