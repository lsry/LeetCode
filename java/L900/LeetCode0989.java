package L900;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode0989 {
    public List<Integer> addToArrayForm(int[] A, int K) {
        List<Integer> res = new ArrayList<>(A.length + 1);
        int carry = 0;
        for (int i = A.length - 1;i >= 0;--i) {
            int sum = A[i] + K % 10 + carry;
            res.add(sum % 10);
            carry = sum / 10;
            K = K / 10;
        }
        while (K != 0) {
            int sum = K % 10 + carry;
            res.add(sum % 10);
            carry = sum / 10;
            K = K / 10;
        }
        if (carry != 0) {
            res.add(carry);
        }
        Collections.reverse(res);
        return res;
    }
}
