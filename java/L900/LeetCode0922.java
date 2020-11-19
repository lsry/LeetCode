package L900;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0922 {
    public int[] sortArrayByParityII(int[] A) {
        List<Integer> even = new ArrayList<>();
        List<Integer> odd = new ArrayList<>();
        for (int a : A) {
            if (a % 2 == 0) {
                even.add(a);
            } else {
                odd.add(a);
            }
        }
        int ei = 0, oi = 0;
        for (int i = 0;i < A.length;++i) {
            if (i % 2 == 0) {
                A[i] = even.get(ei);
                ++ei;
            } else {
                A[i] = odd.get(oi);
                ++oi;
            }
        }
        return A;
    }
}
