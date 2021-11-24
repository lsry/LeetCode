package L500;

import java.util.HashMap;
import java.util.Map;

public class LeetCode0594 {
    public int findLHS(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        int len = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (map.containsKey(entry.getKey() + 1)) {
                len = Math.max(len, entry.getValue() + map.get(entry.getKey() + 1));
            }
            if (map.containsKey(entry.getKey() - 1)) {
                len = Math.max(len, entry.getValue() + map.get(entry.getKey() - 1));
            }
        }
        return len;
    }
}