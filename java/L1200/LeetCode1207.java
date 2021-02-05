package L1200;

import java.util.HashMap;
import java.util.Map;

public class LeetCode1207 {
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int a : arr) {
            map.put(a, map.getOrDefault(a, 0) + 1);
        }
        boolean[] set = new boolean[1001];
        for (Map.Entry<Integer,Integer> entry : map.entrySet()) {
            if (set[entry.getValue()]) {
                return false;
            } 
            set[entry.getValue()] = true;
        }
        return true;
    }
}
