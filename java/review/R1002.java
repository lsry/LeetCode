package review;

import java.util.ArrayList;
import java.util.List;

public class R1002 {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> res = new ArrayList<>();
        if (strs == null || strs.length == 0) {
            return res;
        }
        List<int[]> flags = new ArrayList<>();
        for (String str : strs) {
            int[] flag = new int[26];
            for (char c : str.toCharArray()) {
                flag[c - 'a'] ++;
            }
            int sz = res.size();
            boolean f = true;
            for (int i = 0;i < sz;++i) {
                if (isEqual(flag, flags.get(i))) {
                    res.get(i).add(str);
                    f = false;
                    break;
                }
            }
            if (f) {
                List<String> cList = new ArrayList<>();
                cList.add(str);
                flags.add(flag);
                res.add(cList);
            }
        }
        return res;
    }

    private boolean isEqual(int[] a, int[] b) {
        for (int i = 0;i < a.length;++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
}