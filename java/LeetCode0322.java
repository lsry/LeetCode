import java.util.HashMap;
import java.util.Map;

public class LeetCode0322 {
    public int coinChange(int[] coins, int amount) {
        Map<Integer,Integer> map = new HashMap<>();
        map.put(0, 0);
        int res = help(coins, amount, map);
        return res == Integer.MAX_VALUE ? -1 : res;
    }

    public int help(int[] coins,int amount,Map<Integer,Integer> map) {
        if (amount < 0) {
            return Integer.MAX_VALUE;
        } else if (amount == 0) {
            return 0;
        } else if (map.containsKey(amount)) {
            return map.get(amount);
        }
        int min = Integer.MAX_VALUE;
        for (int c : coins) {
            int t = help(coins, amount - c, map);
            if (t != Integer.MAX_VALUE) {
                min = Math.min(min, t + 1);
            }
        }
        map.put(amount, min);
        return min;
    }
}