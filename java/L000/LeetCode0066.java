package L000;

public class LeetCode0066 {
    public int[] plusOne(int[] digits) {
        int C = 1;
        for (int i = digits.length - 1;i >= 0;--i) {
            int t = digits[i] + C;
            digits[i] = t % 10;
            C = t / 10;
        }
        if (C == 0) {
            return digits;
        } else {
            int[] res = new int[digits.length + 1];
            res[0] = C;
            for (int i = 0;i < digits.length;++i) {
                res[i + 1] = digits[i];
            }
            return res;
        }
    }
}