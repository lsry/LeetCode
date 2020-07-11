package review;

import java.util.ArrayList;
import java.util.List;

public class R1611 {
    public int[] divingBoard(int shorter, int longer, int k) {
        if (k == 0) {
            return new int[]{};
        }
        List<Integer> res = new ArrayList<>(k + 1);
        res.add(-1);
        for (int i = 0;i <= k;++i) {
            int len = i * longer + (k - i) * shorter;
            if (len > res.get(res.size() - 1)) {
                res.add(len);
            }
        }
        int[] rarr = new int[res.size() - 1];
        for (int i = 1;i < res.size();++i) {
            rarr[i - 1] = res.get(i);
        }
        return rarr;
    }
}