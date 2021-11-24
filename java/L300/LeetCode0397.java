package L300;

import java.util.HashMap;

public class LeetCode0397 {
    private HashMap<Integer, Integer> map = new HashMap<>();
    public int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == Integer.MAX_VALUE) return 32;
        if (map.containsKey(n)) {
            return map.get(n);
        }
        if (n % 2 == 0) {
            map.put(n, integerReplacement(n / 2) + 1);
        } else {
            map.put(n, Math.min(integerReplacement(n + 1), integerReplacement(n - 1)) + 1);
        }
        return map.get(n);
    }
}
