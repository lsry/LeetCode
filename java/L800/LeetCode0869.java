package L800;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0869 {
    private static final int[] pow2 = new int[32];
    private static final List<List<Integer>> pow2List;
    static {
        pow2List = new ArrayList<>();
        pow2[0] = 1;
        pow2List.add(getDigit(1));
        for (int i = 1; i < 32;++i) {
            pow2[i] = pow2[i - 1] * 2;
            pow2List.add(getDigit(pow2[i]));
        }
    }
    public boolean reorderedPowerOf2(int n) {
        if (n == 0) {
            return false;
        }
        List<Integer> r2 = getDigit(n);
        for (int i = 0;i < 32;++i) {
            if (pow2[i] == n) {
                return true;
            }
            List<Integer> r1 = pow2List.get(i);
            
            if (r1.size() == r2.size()) {
                boolean flag = true;
                for (int j = 0;j < r1.size();++j) {
                    if (!r1.get(j).equals(r2.get(j))) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;          
                }
            }
        }
        return false;
    }

    private static List<Integer> getDigit(int x) {
        List<Integer> res = new ArrayList<>();
        while (x != 0) {
            res.add(x % 10);
            x = x / 10;
        }
        res.sort((a, b) -> {return a - b;});
        return res;
    }

}
