package L100;

import java.util.Arrays;

public class LeetCode0135 {
    public int candy(int[] ratings) {
        final int N = ratings.length;
        int[] alloc = new int[N];
        alloc[0] = 1;
        for (int i = 1;i < N;++i) {
            if (ratings[i] > ratings[i - 1]) {
                alloc[i] = alloc[i - 1] + 1;
            } else {
                alloc[i] = 1;
            }
        }
        for (int i = N - 2;i >= 0;--i) {
            if (ratings[i] > ratings[i + 1]) {
                alloc[i] = Math.max(alloc[i], alloc[i + 1] + 1);
            } else {
                alloc[i] = Math.max(alloc[i], 1);
            }
        }
        return Arrays.stream(alloc).sum();
    }
}
