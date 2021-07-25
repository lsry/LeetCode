package L1800;

import java.util.Arrays;

public class LeetCode1877 {
    public int minPairSum(int[] nums) {
        Arrays.sort(nums);
        int max = nums[0] + nums[nums.length - 1];
        for (int l = 0, r = nums.length - 1;l < r;++l, --r) {
            max = Math.max(max, nums[l] + nums[r]);
        }
        return max;
    }
}
