import java.util.Arrays;

public class LeetCode0410 {
    public int splitArray(int[] nums, int m) {
        int[][] dp = new int[nums.length + 1][m + 1];
        for (int[] arr : dp) {
            Arrays.fill(arr, Integer.MAX_VALUE);
        }
        dp[0][0] = 0;
        int prefix[] = new int[nums.length + 1];
        for (int i = 1;i < prefix.length;++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for (int i = 1;i <= nums.length;++i) {
            for (int j = 1;j <= Math.min(i, m);++j) {
                for (int k = 0;k < i;++k) {
                    dp[i][j] = Math.min(dp[i][j], Math.max(dp[k][j-1], prefix[i] - prefix[k]));
                }
            }
        }
        return dp[nums.length][m];
    }
}