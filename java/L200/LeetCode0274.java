package L200;

import java.util.Arrays;

public class LeetCode0274 {
    public int hIndex(int[] citations) {
        if (citations == null || citations.length == 0) {
            return 0;
        }
        Arrays.sort(citations);
        for (int h = 0;h < citations.length;++h) {
            if (citations[h] >= citations.length - h) {
                return citations.length - h;
            }
        }
        return 0;
    }
}