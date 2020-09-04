package L300;

public class LeetCode0300 {
    public int lengthOfLIS(int[] nums) {
        int[] lis = new int[nums.length];
        int cur = 0;
        for (int i = nums.length - 1;i >= 0;--i) {
            int max = 1;
            for (int j = i + 1;j < nums.length;++j) {
                if (nums[j] > nums[i] && max < 1 + lis[j]) {
                    max = 1 + lis[j];
                }
            }
            lis[i] = max;
            if (cur < max) {
                cur = max;
            }
        }
        return cur;
    }
}