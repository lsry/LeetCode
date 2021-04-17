package L000;

import java.util.HashMap;

public class LeetCode0087 {
    private int N;
    private HashMap<String,Boolean> map;
    public boolean isScramble(String s1, String s2) {
        N = s1.length();
        map = new HashMap<>();
        return rangeScramble(s1, 0, N - 1, s2, 0, N - 1);
    }

    private boolean rangeScramble(String s1, int b1, int e1, String s2, int b2, int e2) {
        if (e1 - b1 != e2 - b2) {
            return false;
        }
        if (b1 == e1) {
            return s1.charAt(b1) == s2.charAt(b2);
        }
        String key = s1.substring(b1, e1 + 1) + "," + s2.substring(b2, e2 + 1);
        if (map.containsKey(key)) {
            return map.get(key);
        }
        boolean flag = true;
        for (int i = b1, j = b2; i <= e1 && j <= e2;++i, ++j) {
            if (s1.charAt(i) != s2.charAt(j)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            map.put(key, true);
            return true;
        }
        for (int i = 0;b1 + i < e1;++i) {
            // 交换后需要保持长度相等
            if ((rangeScramble(s1, b1, b1 + i, s2, b2, b2 + i) && rangeScramble(s1, b1 + i + 1, e1, s2, b2 + i + 1, e2)) || 
                (rangeScramble(s1, b1 + i + 1, e1, s2, b2, b2 + e1 - b1 - i - 1) && rangeScramble(s1, b1, b1 + i, s2, b2 + e1 - b1 - i, e2))) {
                map.put(key, true);
                return true;
            }
        }
        map.put(key, false);
        return false;
    }
}
