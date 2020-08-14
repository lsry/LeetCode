package L000;

public class LeetCode0045 {
    public int jump(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return 0;
        }
        int[] steps = new int[nums.length];
        steps[nums.length - 1] = 0;
        for (int i = nums.length - 2;i >= 0;--i) {
            if (i + nums[i] >= nums.length - 1) {
                steps[i] = 1;
            } else {
                int step = nums.length;
                for (int j = nums[i];j >= 1;--j) {
                    step = Math.min(step, 1 + steps[i + j]);
                }
                steps[i] = step;
            }
        }
        return steps[0];
    }
}