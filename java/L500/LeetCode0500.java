package L500;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LeetCode0500 {
    private static final List<Set<Character>> rows;
    static {
        rows = new ArrayList<>();
        rows.add(new HashSet<Character>(Arrays.asList(new Character[]{'q','w','e','r','t','y','u','i','o','p'})));
        rows.add(new HashSet<Character>(Arrays.asList(new Character[]{'a','s','d','f','g','h','j','k','l'})));
        rows.add(new HashSet<Character>(Arrays.asList(new Character[]{'z','x','c','v','b','n','m'})));
    }

    public String[] findWords(String[] words) {
        return Arrays.stream(words).filter(x -> {
            String s = x.toLowerCase();
            for (Set<Character> hc : rows) {
                boolean flag = true;
                for (char c : s.toCharArray()) {
                    if (!hc.contains(c)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
            return false;
        }).toArray(String[]::new);
    }   
}
