package L200;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LeetCode0211 {}

class WordDictionary {

    private Map<Integer, Set<String>> dicts;

    public WordDictionary() {
        dicts = new HashMap<>();
    }
    
    public void addWord(String word) {
        Set<String> words = dicts.getOrDefault(word.length(), new HashSet<>());
        words.add(word);
        dicts.put(word.length(), words);
    }
    
    public boolean search(String word) {
        Set<String> words = dicts.get(word.length());
        if (words == null || words.isEmpty()) {
            return false;
        }
        if (words.contains(word)) {
            return true;
        }
        for (String curWord : words) {
            if (curWord.length() != word.length()) {
                continue;
            }
            int len = word.length();
            boolean flag = true;
            for (int i = 0;i < len;++i) {
                if (word.charAt(i) == '.') {
                    continue;
                }
                if (word.charAt(i) != curWord.charAt(i)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
        
}
