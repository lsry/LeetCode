package L700;

import java.util.Arrays;

public class LeetCode0748 {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] lt = new int[26];
        for (char c : licensePlate.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                lt[c - 'a']++;
            } else if (c >= 'A' && c <= 'Z') {
                lt[c - 'A']++;
            }
        }
        int[] rt = new int[26];
        String res = null;
        for (String word : words) {
            Arrays.fill(rt, 0);
            for (char c : word.toCharArray()) {
                rt[c - 'a']++;
            }
            boolean flag = true;
            for (int i = 0;i < 26;++i) {
                if (lt[i] > rt[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag && (res == null || word.length() < res.length())) {
                res = word;
            }
        }
        return res;
    }
}