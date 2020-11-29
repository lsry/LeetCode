package L1100;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class LeetCode1122 {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int a : arr2) {
            map.put(a, 0);
        }
        List<Integer> list = new ArrayList<>();
        for (int a : arr1) {
            if (map.containsKey(a)) {
                map.put(a, map.get(a) + 1);
            } else {
                list.add(a);
            }
        }
        Collections.sort(list);
        int i = 0;
        for (int j = 0;j < arr2.length;++j) {
            int n = map.get(arr2[j]);
            for (int k = 0;k < n;++k) {
                arr1[i] = arr2[j];
                ++i;
            }
        }
        for (int x : list) {
            arr1[i] = x;
            ++i;
        }
        return arr1;
    }
}
