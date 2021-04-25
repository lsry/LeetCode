package L300;

public class LeetCode0377 {
    public int combinationSum4(int[] nums, int target) {
        //Arrays.sort(nums);
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1;i <= target;++i) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
}
