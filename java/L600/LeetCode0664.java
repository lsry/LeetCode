package L600;

public class LeetCode0664 {
    public int strangePrinter(String s) {
        final int N = s.length();
        int[][] dp = new int[N][N];
        return divide(s, 0, N - 1, dp);
    }

    private int divide(String s, int left, int right, int[][] dp) {
        if (left > right) {
            return 0;
        }
        if (dp[left][right] != 0) {
            return dp[left][right];
        }
        if (left == right) {
            dp[left][right] = 1;
            return 1;
        }
        if (s.charAt(left) == s.charAt(right)) {
            dp[left][right] = divide(s, left, right - 1, dp);
        } else {
            dp[left][right] = 101;
            for (int k = left;k < right;++k) {
                dp[left][right] = Math.min(dp[left][right], divide(s, left, k, dp) + divide(s, k + 1, right, dp));
            }
        }
        return dp[left][right];
    }
}
