package L1100;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class LeetCode1178 {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for (String word : words) {
            int mask = 0;
            for (char ch : word.toCharArray()) {
                mask |= (1 << (ch - 'a'));
            }
            if (Integer.bitCount(mask) <= 7) {
                map.put(mask, map.getOrDefault(mask, 0) + 1);
            }
        }
        List<Integer> res = new ArrayList<>(puzzles.length);
        for (String puzzle : puzzles) {
            int total = 0;
            int mask = 0;
            for (int i = 1;i < 7;++i) {
                mask |= (1 << (puzzle.charAt(i) - 'a'));
            }
            int submask = mask;
            do {
                int s = submask | (1 << (puzzle.charAt(0) - 'a'));
                total += map.getOrDefault(s, 0);
                submask = (submask - 1) & mask;
            } while (submask != mask);
            res.add(total);
        }
        return res;
    }
}
