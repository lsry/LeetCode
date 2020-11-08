package L100;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class LeetCode0140 {
    public List<String> wordBreak(String s, List<String> wordDict) {
        List<String> res = new ArrayList<>();
        if (s == null || s.length() == 0 || wordDict == null || wordDict.isEmpty()) {
            return res;
        }
        HashMap<Integer,List<List<String>>> map = new HashMap<>();
        Set<String> wordSet = new HashSet<>(wordDict);
        List<List<String>> wordbreaks = backtrace(s, 0, wordSet, map);
        for (List<String> wordbreak : wordbreaks) {
            res.add(String.join(" ", wordbreak));
        }
        return res;
    }
    private List<List<String>> backtrace(String s, int index, Set<String> wordSet, HashMap<Integer,List<List<String>>> map) {
        if (!map.containsKey(index)) {
            List<List<String>> wordBreaks = new LinkedList<>();
            if (index >= s.length()) {
                wordBreaks.add(new LinkedList<>());
            } 
            for (int i = index + 1;i <= s.length();++i) {
                String word = s.substring(index, i);
                if (wordSet.contains(word)) {
                    List<List<String>> nextWordBreaks = backtrace(s, i, wordSet, map);
                    for (List<String> nextWordBreak : nextWordBreaks) {
                        List<String> cur = new LinkedList<>(nextWordBreak);
                        cur.add(0, word);
                        wordBreaks.add(cur);
                    }
                }
            }
            map.put(index, wordBreaks);
        }
        return map.get(index);
    }
}
