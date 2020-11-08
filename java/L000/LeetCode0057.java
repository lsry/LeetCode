package L000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0057 {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> res = new ArrayList<>();
        int i = 0;
        for (;i < intervals.length;++i) {
            if (newInterval[0] > intervals[i][1]) {
                int[] cur = new int[2];
                cur[0] = intervals[i][0];
                cur[1] = intervals[i][1];
                res.add(cur);
            } else {
                break;
            }
        }
        if (i == intervals.length || newInterval[1] < intervals[i][0]) {
            res.add(newInterval);
        } else {
            int[] cur = new int[2];
            cur[0] = Math.min(intervals[i][0], newInterval[0]);
            cur[1] = Math.max(intervals[i][1], newInterval[1]);
            for (i = i + 1;i < intervals.length;++i) {
                if (cur[1] >= intervals[i][0]) {
                    cur[1] = Math.max(cur[1], intervals[i][1]);
                } else {
                    break;
                }
            }
            res.add(cur);
        }
        for (;i < intervals.length;++i) {
            res.add(intervals[i]);
        }
        int[][] resArr = new int[res.size()][2];
        for (int k = 0;k < resArr.length;++k) {
            resArr[k] = res.get(k);
        }
        return resArr;
    }
}
