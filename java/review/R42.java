package review;

public class R42 {
    /**
     * maxSum = Max(sum + nums[i], nums[i])
     * 假设之前已经有一段序列形成了和，那么如果加上下一个数变大，则继续向右扩展，
     * 否则使用下一个数当作下一段序列开头
     */
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int max = nums[0];
        int sum = nums[0];
        for (int i = 1;i < nums.length;++i) {
            if (sum + nums[i] > nums[i]) {
                sum += nums[i]; 
            } else {
                sum = nums[i];
            }
            max = Math.max(max, sum);
        }
        return max;
    }
}