package L100;

public class LeetCode0154 {
    public int findMin(int[] nums) {
        int min = 0;
        for (int l = 0, r = nums.length - 1;l <= r;) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[min]) {
                min = m;
            }
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m - 1;
            } else {
                while (l <= r && nums[l] == nums[m] && l <= m) {
                    ++l;
                }
                while (l <= r && nums[r] == nums[m] && r >= m) {
                    --r;
                }
            }
        }
        return nums[min];
    }
}