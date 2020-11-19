package L200;

public class LeetCode0283 {
    public void moveZeroes(int[] nums) {
        int i = -1;
        for (int j = 0;j < nums.length;++j) {
            if (nums[j] != 0) {
                ++i;
                nums[i] = nums[j];
            }
        }
        while (i < nums.length - 1) {
            ++i;
            nums[i] = 0;
        }
    }
}
