package L400;

import java.util.TreeMap;

public class LeetCode0456 {
    public boolean find132pattern(int[] nums) {
        final int N = nums.length;
        if (N < 3) {
            return false;
        }
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 2;i < N;++i) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        int leftmin = nums[0];
        for (int i = 1;i < N - 1;++i) {
            if (leftmin < nums[i]) {
                Integer v = map.ceilingKey(leftmin + 1);
                if (v != null && v < nums[i]) {
                    return true;
                }
            }
            leftmin = Math.min(leftmin, nums[i]);
            map.put(nums[i + 1], map.get(nums[i + 1]) - 1);
            if (map.get(nums[i + 1]) == 0) {
                map.remove(nums[i + 1]);
            }
        }
        return false;
    }
}
