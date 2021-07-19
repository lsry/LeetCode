package L1800;

import java.util.Arrays;

public class LeetCode1838 {
    public int maxFrequency(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int max = 1;
        Arrays.sort(nums);
        int remain = k;
        for (int r = nums.length - 1, l = nums.length - 1;l > 0 && r > 0;) {
            while (l - 1 >= 0 && nums[r] - nums[l - 1] <= remain) {
                remain -= nums[r] - nums[l - 1];
                --l;
            }
            max = Math.max(max, r - l + 1);
            remain += (r - l) * (nums[r] - nums[r - 1]);
            --r;
        }
        return max;
    }
}