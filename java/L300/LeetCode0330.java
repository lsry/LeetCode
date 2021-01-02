package L300;

public class LeetCode0330 {
    /**
     * 按照 1, ... , n 的顺序遍历
     * 假设当前所能覆盖的范围[1,...,sum], 那么当添加一个数 x 以后，能够覆盖的范围[1,...,sum + x]
     */
    public int minPatches(int[] nums, int n) {
        long sum = 0;
        long next = 1;
        int ans = 0;
        for (int i = 0;i < nums.length;++i) {
            if (sum >= n) {
                break;
            }
            while (next < nums[i] && sum < n) {
                ++ans;
                sum += next;
                next = sum + 1;
            }
            if (sum >= n) {
                break;
            }
            sum += nums[i];
            next = sum + 1;
        }
        while (sum < n) {
            ++ans;
            sum += next;
            next = sum + 1;
        }
        return ans;
    }
}
