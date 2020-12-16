package L300;

public class LeetCode0376 {
    public int wiggleMaxLength(int[] nums) {
        if (nums.length <= 1) {
            return nums.length;
        }
        int i = 1;
        while (i < nums.length && nums[i] == nums[i - 1]) {
            ++i;
        }
        if (i == nums.length) {
            return 1;
        }
        int ans = 2;
        int last = nums[i];
        boolean sign = nums[i] - nums[i - 1] < 0 ? false : true;
        for (i = i + 1;i < nums.length;++i) {
            if (sign) {
                if (nums[i] - last < 0) {
                    sign = false;
                    ++ans;
                }
                last = nums[i];
            } else {
               if (nums[i] - last > 0) {
                   sign = true;
                   ++ans;
               }
               last = nums[i];
            }
        }
        return ans;
    }
}
