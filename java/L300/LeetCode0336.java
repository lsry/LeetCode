package L300;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class LeetCode0336 {
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>> res = new ArrayList<>();
        if (words.length < 2) {
            return res;
        }
        HashMap<String,Integer> msi = new HashMap<>();
        for (int i = 0;i < words.length;++i) {
            msi.put(new StringBuilder(words[i]).reverse().toString(), i);
        }
        for (int i = 0;i < words.length;++i) {
            int sn = words[i].length();
            if (sn == 0) {
                continue;
            }
            for (int j = 0;j <= sn;++j) {
                if (isPalindrome(words[i], j, sn - 1)) {
                    int rn = mapFind(words[i], 0, j - 1, msi);
                    if (rn != -1 && rn != i) {
                        res.add(Arrays.asList(i,rn));
                    }
                }
                if (j != 0 && isPalindrome(words[i], 0, j - 1)) {
                    int ln = mapFind(words[i], j, sn - 1, msi);
                    if (ln != -1 && ln != i) {
                        res.add(Arrays.asList(ln,i));
                    }
                }
            }
        }
        return res;
    }

    public int mapFind(String str,int left,int right,HashMap<String,Integer> msi) {
        return msi.getOrDefault(str.substring(left, right + 1), -1);
    }

    public boolean isPalindrome(String str,int left,int right) {
        if (left > right) {
            return true;
        }
        int len = right - left + 1;
        for (int i = 0;i <= len / 2;++i) {
            if (str.charAt(left + i) != str.charAt(right - i)) {
                return false;
            }
        }
        return true;
    }
}