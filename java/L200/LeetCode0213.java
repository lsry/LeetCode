package L200;

import java.util.Arrays;

public class LeetCode0213 {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        } else if (nums.length == 1) {
            return nums[0];
        } else if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        // 以 0 开头
        int[] maxs = new int[nums.length];
        boolean[] flags = new boolean[nums.length];
        maxs[0] = nums[0];
        flags[0] = true;
        maxs[1] = nums[1];
        for (int i = 2;i < nums.length - 1;++i) {
            int a = i - 2 >= 0 ? maxs[i - 2] : 0;
            int b = i - 3 >= 0 ? maxs[i - 3] : 0;
            if (a >= b) {
                maxs[i] = a + nums[i];
                if (i - 2 >= 0) {
                    flags[i] = flags[i - 2];
                }
            } else if (b > a) {
                maxs[i] = b + nums[i];
                if (i - 3 >= 0) {
                    flags[i] = flags[i - 3];
                }
            }
        }
        int ix = nums.length - 1;
        if (ix > 1) {   
            int a = (ix - 2 >= 0 && flags[ix - 2] == false) ? maxs[ix - 2] : (ix - 2 > 0 ? maxs[ix - 2] - maxs[0] : 0);
            int b = (ix - 3 >= 0 && flags[ix - 3] == false) ? maxs[ix - 3] : (ix - 3 > 0 ? maxs[ix - 3] - maxs[0] : 0);
            maxs[ix] = Math.max(a, b) + nums[ix];
        }
        int max1 = Math.max(maxs[ix], Math.max(maxs[ix - 1], maxs[ix - 2]));
        // 以 1 开头
        Arrays.fill(maxs, 0);
        maxs[1] = nums[1];
        for (int i = 2;i < nums.length;++i) {
            int a = i - 2 >= 0 ? maxs[i - 2] : 0;
            int b = i - 3 >= 0 ? maxs[i - 3] : 0;
            maxs[i] = Math.max(a, b) + nums[i];
        }
        int max2 = Math.max(maxs[ix], Math.max(maxs[ix - 1], maxs[ix - 2]));
        return Math.max(max1, max2);
    }
}
