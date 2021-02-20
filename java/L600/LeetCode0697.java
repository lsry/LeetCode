package L600;

import java.util.HashMap;

public class LeetCode0697 {
    public int findShortestSubArray(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int deg = 0;
        for (int n : nums) {
            int ndeg = map.getOrDefault(n, 0) + 1;
            deg = Math.max(deg, ndeg);
            map.put(n, ndeg);
        }
        int len = Integer.MAX_VALUE;
        map.clear();
        int i = 0, j = 0;
        while (j < nums.length) {
            map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
            if (map.get(nums[j]) == deg) {
                while (nums[i] != nums[j]) {
                    map.put(nums[i], map.get(nums[i]) - 1);
                    ++i;
                }
                len = Math.min(len, j - i + 1);
            }
            ++j;
        }
        return len;
    }
}
