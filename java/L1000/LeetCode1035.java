package L1000;

public class LeetCode1035 {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        final int M = nums1.length, N = nums2.length;
        int[][] dp = new int[M + 1][N + 1];
        for (int i = 1;i <= M;++i) {
            for (int j = 1;j <= N;++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[M][N];
    }
}
