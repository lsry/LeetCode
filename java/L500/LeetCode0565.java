package L500;

public class LeetCode0565 {
    // 依次按照数组内容访问元素，同时记录该位置可到达的最大长度，选取最大值
    public int arrayNesting2ms(int[] nums) {
        int[] dp = new int[nums.length];
        for (int i = 0;i < dp.length;i++){
            dp[i] = -1;
        }
        boolean[] flags = new boolean[nums.length];
        int max = -1;
        for (int i = 0;i < nums.length;i++){
            max = Math.max(max, helper(nums,dp,flags,i));
        }
        return max;
    }

    private int helper(int[] nums,int[] dp,boolean[] flags,int index){
        if (dp[index] != -1){
            return dp[index];
        } else if (flags[index] == true){
            return 0;
        }
        flags[index] = true;
        int len = 1 + helper(nums, dp, flags, nums[index]);
        flags[index] = false;
        dp[index] = len;
        return len;
    }

    // 记录访问过的，不再访问
    public int arrayNesting4ms(int[] nums) {
        boolean[] visited  = new boolean[nums.length];
        int res = 0;
        for (int i = 0;i < nums.length;++i) {
            if (visited[i] == false) {
                int count = 0;
                int j = i;
                while (visited[j] == false) {
                    count++;
                    visited[j] = true;
                    j = nums[j];
                }
                res = Math.max(res, count);
            }
        }
        return res;
    }
}