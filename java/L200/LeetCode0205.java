package L200;

import java.util.HashMap;

public class LeetCode0205 {
    public boolean isIsomorphic(String s, String t) {
        HashMap<Character,Character> sMap = new HashMap<>();
        HashMap<Character,Character> tMap = new HashMap<>();
        final int N = s.length();
        for (int i = 0;i < N;++i) {
            char cs = s.charAt(i);
            char ct = t.charAt(i);
            if (!sMap.containsKey(cs) && !tMap.containsKey(ct)) {
                sMap.put(cs, ct);
                tMap.put(ct, cs);
            } else if (sMap.containsKey(cs) && tMap.containsKey(ct)) {
                if (sMap.get(cs) != ct || tMap.get(ct) != cs) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
}
