public class LeetCode0053 {
    public int maxSubArray(int[] nums) {
        int max = Integer.MIN_VALUE;
        int cur = 0;
        for (int num : nums) {
            cur += num;
            max = max > cur ? max : cur;
            if (cur <= 0) {
                cur = 0;
            }
        }
        return max;
    }
}