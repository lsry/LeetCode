package L500;

import java.util.HashMap;

public class LeetCode0523 {
    /**
     * 计算前缀和，然后枚举两个边界，计算是否为目标值
     * 当前 TLE
     */
    public boolean checkSubarraySumTLE(int[] nums, int k) {
        int[] preSum = new int[nums.length];
        preSum[0] = nums[0];
        for (int i = 1;i < nums.length;i++){
            preSum[i] = preSum[i-1] + nums[i];
        }
        for (int i = 0;i < nums.length - 1;i++){
            for (int j = i + 1;j < nums.length;j++){
                int sum = preSum[j] - preSum[i] + nums[i];
                if (sum == k || (k != 0 && sum % k == 0)){
                    return true;
                }
            }
        }
        return false;
    }

    /**
     * 同余定理：当两个子数组余数相同，其差也为 k 的整数倍
     * S1 = n1 * k + r;
     * S2 = n2 * k + r;
     * S2 - S1 = (n2 - n1) * k
     */
    public boolean checkSubarraySum(int[] nums, int k) {
        final int N = nums.length;
        if (N < 2) {
            return false;
        }
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0, -1);
        int r = 0;
        for (int i = 0;i < N;++i) {
            r = (r + nums[i]) % k;
            if (map.containsKey(r)) {
                int index = map.get(r);
                if (i - index >= 2) {
                    return true;
                }
            } else {
                map.put(r, i);
            }
        }
        return false;
    }
}