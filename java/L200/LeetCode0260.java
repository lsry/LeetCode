package L200;

public class LeetCode0260 {
    public int[] singleNumber(int[] nums) {
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        int k = 0;
        for (int i = 31;i >= 0;--i) {
            if (((xor >>> i) & 1) == 1) {
                k = i;
                break;
            }
        }
        int[] ans = new int[2];
        for (int num : nums) {
            if (((num >>> k) & 1) == 1) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
}
