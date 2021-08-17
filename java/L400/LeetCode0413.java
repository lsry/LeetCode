package L400;

public class LeetCode0413 {
    public int numberOfArithmeticSlices(int[] nums) {
        if (nums == null || nums.length < 3) {
            return 0;
        }
        int ans = 0;
        for (int i = 0;i < nums.length;) {
            if (i + 1 >= nums.length - 1) {
                break;
            }
            int diff = nums[i + 1] - nums[i];
            int j = i + 2;
            for (;j < nums.length;++j) {
                if (nums[j] - nums[j - 1] != diff) {
                    break;
                }
            }
            int n = j - i;
            ans += (n - 2) * (n + 3) / 2 - 2 * n + 4;
            i = j - 1;
        }
        return ans;
    }
}
