package L1900;

import java.util.HashMap;

public class LeetCode1995 {
    public int countQuadruplets(int[] nums) {
        int ans = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0;i < nums.length - 3;++i) {
            for (int j = i + 1;j < nums.length - 2;++j) {
                map.clear();
                for (int k = j + 1;k < nums.length;++k) {
                    ans += map.getOrDefault(nums[k] - nums[i] - nums[j], 0);
                    map.put(nums[k], map.getOrDefault(nums[k], 0) + 1);
                }
            }
        }
        return ans;
    }
}
