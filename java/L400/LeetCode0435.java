package L400;

import java.util.Arrays;

public class LeetCode0435 {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length <= 1) {
            return 0;
        }
        Arrays.sort(intervals,(i1, i2) -> {
            return i1[1] - i2[1];
        });
        int right = intervals[0][1];
        int ans = 1;
        for (int i = 1;i < intervals.length;++i) {
            if (intervals[i][0] >= right) {
                ++ans;
                right = intervals[i][1];
            }
        }
        return intervals.length - ans;
    }
}
