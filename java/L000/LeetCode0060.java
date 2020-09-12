package L000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0060 {
    private int tar = 1;
    private StringBuilder restr = new StringBuilder();
    public String getPermutation(int n, int k) {
        List<Integer> res = new ArrayList<>(n);
        boolean[] visit = new boolean[n + 1];
        tar = k;
        backtrace(n, 0, res, visit);
        return restr.toString();
    }
    private boolean backtrace(int n, int index, List<Integer> res, boolean[] visit) {
        if (index == n) {
            if (tar == 1) {
                for (int i : res) {
                    restr.append(i);   
                }
                return true;
            } else {
                tar--;
                return false;
            }
        }
        for (int i = 1;i <= n;++i) {
            if (visit[i] == false) {
                visit[i] = true;
                res.add(i);
                if (backtrace(n, index + 1, res, visit)) {
                    return true;
                } else {
                    visit[i] = false;
                    res.remove(res.size() - 1);
                }
            }
        }
        return true;
    }
}
