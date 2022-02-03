package L800;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LeetCode0884 {
    public String[] uncommonFromSentences(String s1, String s2) {
        String[] w1 = s1.split("\\s+");
        String[] w2 = s2.split("\\s+");
        HashMap<String, Integer> m1 = new HashMap<>();
        for (String w : w1) {
            m1.put(w, m1.getOrDefault(w, 0) + 1);
        }
        HashMap<String, Integer> m2 = new HashMap<>();
        for (String w : w2) {
            m2.put(w, m2.getOrDefault(w, 0) + 1);
        }
        List<String> rList = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : m1.entrySet()) {
            if (entry.getValue() == 1 && !m2.containsKey(entry.getKey())) {
                rList.add(entry.getKey());
            }
        }
        for (Map.Entry<String, Integer> entry : m2.entrySet()) {
            if (entry.getValue() == 1 && !m1.containsKey(entry.getKey())) {
                rList.add(entry.getKey());
            }
        }
        return rList.stream().toArray(String[]::new);
    }
}
