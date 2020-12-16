package L700;

public class LeetCode0738 {
    public int monotoneIncreasingDigits(int N) {
        int[] digits = new int[11];
        int end = -1;
        while (N != 0) {
            ++end;
            digits[end] = N % 10;
            N /= 10;
        }
        int last = -1;
        int t = 0;
        for (int i = 0;i < end;++i) {
            if (digits[i] < digits[i + 1]) {
                for (int j = last + 1;j <= i;++j) {
                    digits[j] = 9;
                }
                last = i;
                digits[i + 1] -= 1;
                if (digits[i + 1] == 0 && i + 1 == end) {
                    ++t;
                }
            }
        }
        end -= t;
        int res = 0;
        for (int i = end;i >= 0;--i) {
            res = res * 10 + digits[i];
        }
        return res;
    }
}
