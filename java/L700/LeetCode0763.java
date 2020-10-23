package L700;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0763 {
    public List<Integer> partitionLabels(String S) {
        List<Integer> res = new ArrayList<>();
        if (S == null || S.length() == 0) {
            return res;
        }
        int[] chp = new int[26];
        for (int i = 0;i < S.length();++i) {
            chp[S.charAt(i) - 'a'] = i;
        }
        int last = -1;
        for (int i = 0;i < S.length();) {
            int rx = chp[S.charAt(i) - 'a'];
            int j = i;
            while (j <= rx) {
                if (chp[S.charAt(j) - 'a'] > rx) {
                    rx = chp[S.charAt(j) - 'a'];
                }
                ++j;
            }
            res.add(rx - last);
            i = rx + 1;
            last = rx;
        }
        return res;
    }
}
