package L400;

public class LeetCode0416 {
    /**
     * 0-1 package   
     * 从数组中挑选一定的数，判断其和是否等于一半的总和
     */
    public boolean canPartitionInt(int[] nums) {
        int sum = 0;
        for (int n : nums){
            sum += n;
        }
        if (sum % 2 == 1){
            return false;
        }
        int half = sum >> 1;
        int[] arr = new int[half + 1];
        for (int i = 0;i < nums.length;i++){
            for (int j = half;j - nums[i] >= 0;j--){
                int curSum = nums[i] + arr[j - nums[i]];
                if (curSum == half){
                    return true;
                }
                if (curSum <= j){
                    arr[j] = curSum;
                }
            }
        }
        return false;
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int n : nums){
            sum += n;
        }
        if (sum % 2 == 1){
            return false;
        }
        int half = sum >> 1;
        boolean[] dp = new boolean[half + 1];
        dp[0] = true;
        for (int i = 0;i < nums.length;++i) {
            for (int j = half;j - nums[i] >= 0;--j) {
                dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[half];
    }
}