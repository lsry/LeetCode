package L200;

public class LeetCode0238 {
    public int[] productExceptSelf(int[] nums) {
        int[] out = new int[nums.length];
        out[0] = 1;
        for (int i = 1;i < nums.length;++i) {
            out[i] = out[i - 1] * nums[i - 1];
        }
        int sup = 1;
        for (int i = nums.length - 2;i >= 0;--i) {
            sup *= nums[i + 1];
            out[i] *= sup;
        }
        return out;
    }
}