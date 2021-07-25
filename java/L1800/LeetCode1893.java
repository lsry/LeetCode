package L1800;

import java.util.Arrays;

public class LeetCode1893 {
    public boolean isCovered(int[][] ranges, int left, int right) {
        Arrays.sort(ranges, (a, b) -> {
            if (a[0] == b[0]) {
                return a[1] - b[1];
            } else {
                return a[0] - b[0];
            }
        });
        int x = left;
        int i = 0;
        while (x <= right) {
            while (i < ranges.length && x > ranges[i][1]) {
                ++i;
            }
            if (i >= ranges.length || x < ranges[i][0]) {
                break;
            }
            ++x;
        }
        return x > right;
    }
}
