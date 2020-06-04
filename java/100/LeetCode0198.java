public class LeetCode0198 {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        } else if (nums.length == 1) {
            return nums[0];
        }
        int[] dp = new int[nums.length];
        for (int i = nums.length - 1;i >= 0;--i) {
            int next1 = i + 2 < nums.length ? dp[i + 2] : 0;
            int next2 = i + 3 < nums.length ? dp[i + 3] : 0;
            dp[i] = nums[i] + Math.max(next1, next2);
        }
        return Math.max(dp[0], dp[1]);
    }
}