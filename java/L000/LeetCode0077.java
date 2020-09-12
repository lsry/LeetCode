package L000;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LeetCode0077 {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        trace(res, new HashSet<>(), n, 1, k);
        return res;
    }

    private void trace(List<List<Integer>> res,Set<Integer> si, int n, int index, int c) {
        if (c == 0) {
            res.add(new ArrayList<>(si));
            return;
        }
        for (int i = index;i <= n - c + 1;++i) {
            if (!si.contains(i)) {
                si.add(i);
                trace(res, si, n, i + 1, c - 1);
                si.remove(i);
            }
        }
    }
}
