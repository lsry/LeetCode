package L300;

public class LeetCode0312 {
    public int maxCoins(int[] nums) {
        int[] ns = new int[nums.length + 2];
        ns[0] = 1;
        ns[nums.length + 1] = 1;
        for (int i = 0;i < nums.length;++i) {
            ns[i + 1] = nums[i];
        }
        int[][] dp = new int[nums.length + 2][nums.length + 2];
        for (int i = nums.length + 1;i >= 0;--i) {
            for (int j = i + 2;j < nums.length + 2;++j) {
                for (int k = i + 1;k < j;++k) {
                    dp[i][j] = Math.max(dp[i][j], ns[i]*ns[k]*ns[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][nums.length + 1];
    }
}