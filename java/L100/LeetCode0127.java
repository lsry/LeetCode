package L100;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode0127 {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        int wordSz = wordList.size();
        HashMap<String,Integer> map = new HashMap<>();
        for (int i = 0;i < wordSz;++i) {
            map.put(wordList.get(i), i);
        }
        boolean[] flags = new boolean[wordSz];
        Queue<String> qStr = new LinkedList<>();
        qStr.offer(beginWord);
        int res = 0;
        while (!qStr.isEmpty()) {
            ++res;
            int sz = qStr.size();
            for (int j = 0;j < sz;++j) {
                String cur = qStr.poll();
                if (cur.equals(endWord)) {
                    return res;
                }
                char[] word = cur.toCharArray();
                for (int i = 0;i < word.length;++i) {
                    char old = word[i];
                    for (char c = 'a';c <= 'z';++c) {
                        if (c != old) {
                            word[i] = c;
                            String str = String.valueOf(word);
                            if (map.containsKey(str) && !flags[map.get(str)]) {
                                qStr.offer(str);
                                flags[map.get(str)] = true;
                            }
                        }
                    }
                    word[i] = old;
                }
            }
            if (res > wordList.size() + 1) {
                break;
            } 
        }
        return 0;
    }
}
