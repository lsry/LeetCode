package L100;

import java.util.HashMap;
import java.util.Map;

public class LeetCode0169 {
    public int majorityElement(int[] nums) {
        int N = -1;
        Map<Integer,Integer> mp = new HashMap<>();
        for (int x : nums) {
            int c = mp.getOrDefault(x, 0) + 1;
            if (c > nums.length / 2) {
                N = x;
                break;
            }
            mp.put(x, c);
        }
        return N;
    }
}