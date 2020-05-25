import java.util.HashMap;
import java.util.Map;

public class LeetCode0076 {
    public String minWindow(String s, String t) {
        if (t == null || t.length() == 0) {
            return "";
        }
        int start = -1, len = Integer.MAX_VALUE;
        HashMap<Character,Integer> table = new HashMap<>();
        for (char c : t.toCharArray()) {
            table.put(c, table.getOrDefault(c, 0) + 1);
        }
        HashMap<Character,Integer> sable = new HashMap<>();
        int left = 0, right = 0;
        char ch;
        int valid = 0;
        while (right < s.length()) {
            ch = s.charAt(right);
            ++right;
            if (table.containsKey(ch)) {
                sable.put(ch, sable.getOrDefault(ch, 0) + 1);
                if (sable.get(ch).equals(table.get(ch))) {
                    ++valid;
                }
            }
            while (valid == table.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                ch = s.charAt(left);
                ++left;
                if (table.containsKey(ch)) {                   
                    if (sable.get(ch).equals(table.get(ch))) {
                        --valid;
                    }
                    sable.put(ch, sable.get(ch) - 1);
                }
                
            }            
        }
        return start == -1 ? "" : s.substring(start, start + len);
    }
}