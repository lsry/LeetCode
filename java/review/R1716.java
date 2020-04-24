package review;

import java.util.Arrays;

public class R1716 {
    public int massage(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        } else if (nums.length == 1) {
            return nums[0];
        }
        int[] dp = new int[nums.length];
        Arrays.fill(dp,-1);
        help(nums,0,dp);
        help(nums,1,dp);
        return Math.max(dp[0], dp[1]);
    }

    public int help(int[] nums,int index,int[] dp) {
        if (index >= nums.length) {
            return 0;
        } else if (dp[index] != -1) {
            return dp[index];
        }
        dp[index] = nums[index] + Math.max(help(nums, index + 2, dp), help(nums, index + 3, dp));
        return dp[index];
    }
}