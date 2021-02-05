package L1100;

import java.util.HashMap;
import java.util.Map;

public class LeetCode1128 {
    public int numEquivDominoPairs(int[][] dominoes) {
        HashMap<String,Integer> map = new HashMap<>();
        for (int[] dominoe : dominoes) {
            String key = (dominoe[0] <= dominoe[1]) ? dominoe[0] + ":" + dominoe[1] : dominoe[1] + ":" + dominoe[0];
            map.put(key, map.getOrDefault(key, 0) + 1);
        }
        int ans = 0;
        for (Map.Entry<String,Integer> entry : map.entrySet()) {
            int v = entry.getValue();
            ans += v * (v - 1) / 2;
        }
        return ans;
    }
}
