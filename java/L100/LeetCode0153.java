package L100;

public class LeetCode0153 {
    public int findMin(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int min = nums[0];
        for (int l = 0, r = nums.length - 1;l <= r;) {
            int m = l + (r - l) / 2;
            min = Math.min(nums[m], min);
            min = Math.min(nums[l], min); // 无法解决全升序的情况
            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return min;
    }
}
