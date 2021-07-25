package L1700;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;

public class LeetCode1743 {
    public int[] restoreArray(int[][] adjacentPairs) {
        HashMap<Integer, List<Integer>> map = new HashMap<>(adjacentPairs.length * 4 / 3);
        for (int[] pair : adjacentPairs) {
            List<Integer> list1 = map.getOrDefault(pair[0], new ArrayList<>());
            if (list1.isEmpty() || (list1.size() == 1 && !list1.get(0).equals(pair[1]))) {
                list1.add(pair[1]);
            }
            map.put(pair[0], list1);
            List<Integer> list2 = map.getOrDefault(pair[1], new ArrayList<>());
            if (list2.isEmpty() || (list2.size() == 1 && !list2.get(0).equals(pair[0]))) {
                list2.add(pair[0]);
            }
            map.put(pair[1], list2);
        }
        int first = 0;
        for (Map.Entry<Integer,List<Integer>> entry : map.entrySet()) {
            if (entry.getValue().size() == 1) {
                first = entry.getKey();
                break;
            }
        }
        int[] res = new int[adjacentPairs.length + 1];
        res[0] = first;
        HashSet<Integer> set = new HashSet<>(res.length);
        set.add(first);
        for (int i = 0;i + 1 < res.length;) {
            List<Integer> curList = map.get(res[i]);
            for (Integer x : curList) {
                if (!set.contains(x)) {
                    ++i;
                    res[i] = x;
                    set.add(x);
                    break;
                }
            }
        }
        return res;
    }
}