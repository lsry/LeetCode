package L700;

public class LeetCode0747 {
    public int dominantIndex(int[] nums) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int max = 0, max2th = -1;
        for (int i = 1;i < nums.length;++i) {
            if (nums[i] >= nums[max]) {
                max2th = max;
                max = i;
            } else if (max2th == -1 || nums[i] > nums[max2th]) {
                max2th = i;
            }
        }
        return (max2th == -1 || nums[max] >= 2 * nums[max2th]) ? max : -1;
    }
}
