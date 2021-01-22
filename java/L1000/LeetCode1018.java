package L1000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode1018 {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> res = new ArrayList<>(A.length);
        int ans = 0;
        for (int a : A) {
            ans = (ans * 2 + a) % 5;
            if (ans == 0) {
                res.add(Boolean.TRUE);
            } else {
                res.add(Boolean.FALSE);
            }
        }
        return res;
    }
}
