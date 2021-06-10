package L400;

public class LeetCode0474 {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (String str : strs) {
            int zero = getZero(str);
            int one = str.length() - zero;
            // 从大到小是为了和原值作比较，从小到大会导致 dp[i - zero][j - one] 变成新值而产生覆盖
            for (int i = m;i >= zero;--i) {
                for (int j = n;j >= one;--j) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        return dp[m][n];
    }

    private int getZero(String s) {
        int zero = 0;
        for (char c : s.toCharArray()) {
            if (c == '0') {
                ++zero;
            }
        }
        return zero;
    }
}
