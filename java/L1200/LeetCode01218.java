package L1200;

import java.util.HashMap;

public class LeetCode01218 {
    public int longestSubsequence(int[] arr, int difference) {
        if (arr == null) {
            return 0;
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        int max = 0;
        for (int i = 0;i < arr.length;++i) {
            int len = map.getOrDefault(arr[i] - difference, 0) + 1;
            if (len > max) {
                max = len;
            }
            map.put(arr[i], len);
        }
        return max;
    }
}
