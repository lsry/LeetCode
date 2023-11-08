package L300;

public class LeetCode0390 {
    public int lastRemaining(int n) {
        int a1 = 1;
        int k = 0;
        int cnt = n, step = 1;
        while (cnt > 1) {
            if (k % 2 == 0) {
                if (cnt % 2 == 0) {
                    a1 += step;
                } else {
                    a1 += step;
                }
            } else {
                if (cnt % 2 != 0) {
                    a1 += step;
                }
            }
            cnt /= 2;
            step *= 2;
            ++k;
        }
        return a1;
    }
}
