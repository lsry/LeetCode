package L200;

public class LeetCode0209 {
    public int minSubArrayLen(int s, int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int ans = nums.length + 1, sum = 0;
        for (int i = 0, j = 0;j < nums.length;) {
            while (j < nums.length && sum < s) {
                sum += nums[j];
                ++j;
            }
            while (i <= j && sum >= s) {
                ans = Math.min(ans, j - i);
                sum -= nums[i];
                ++i;
            }
        }
        return ans == nums.length + 1 ? 0 : ans;
    }
}