package L1100;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode1104 {
    public List<Integer> pathInZigZagTree(int label) {
        int[] min2 = new int[31];
        min2[0] = 1;
        for (int i = 1;i < 31;++i) {
            min2[i] = min2[i - 1] * 2;
        }
        int level = (int)(Math.log(label) / Math.log(2));
        List<Integer> res = new ArrayList<>(level);
        while (label != 1) {
            res.add(label);
            label = min2[level] - 1 - (label / 2) + min2[level - 1];
            --level;
        }
        res.add(1);
        Collections.reverse(res);
        return res;
    }
}