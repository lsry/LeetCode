package L200;

import java.util.HashMap;

public class LeetCode0233 {
    /**
     * 1. 只承受得住千万级别
     */
    public int countDigitOne1(int n) {
        int count = 0;
        for (int i = 1;i <= n;i++){
            count += ones(i);
        }
        return count;
    }

    public int ones(int n){
        String num = String.valueOf(n);
        int count = 0;
        for (int i = 0;i < num.length();i++){
            if (num.charAt(i) == '1'){
                count++;
            }
        }
        return count;
    }

    HashMap<Integer,Integer> map = new HashMap<>();
    public int countDigitOne(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 9) {
            return 1;
        }
        if (map.containsKey(n)) {
            return map.get(n);
        }
        String ns = String.valueOf(n);
        int fi = ns.charAt(0) - '0';
        int ei = Integer.parseInt(ns.substring(1));
        StringBuilder nb = new StringBuilder();
        for (int i = 0;i < ns.length() - 1;++i) {
            nb.append('9');
        }
        int nines = Integer.parseInt(nb.toString());
        int res = countDigitOne(ei) + fi * countDigitOne(nines);
        if (fi > 1) {
            res += nines + 1;
        } else {
            res += ei + 1;
        }
        map.put(n, res);
        return res;
    }
}