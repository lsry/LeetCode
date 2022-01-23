package L500;

import java.util.List;
import java.util.stream.Collectors;

public class LeetCode0539 {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> seconds = timePoints.stream().map(str -> {
            String[] times = str.split(":");
            return Integer.valueOf(times[0]) * 60 + Integer.valueOf(times[1]);
        }).sorted().collect(Collectors.toList());
        seconds.add(seconds.get(0) + 24 * 60);
        int diff = Integer.MAX_VALUE;
        for (int i = 1;i < seconds.size();++i) {
            int curdiff = seconds.get(i) - seconds.get(i - 1);
            diff = Math.min(diff, Math.min(curdiff, curdiff < 24 * 60 ? 24 * 60 - curdiff : curdiff));
        }
        return diff;
    } 
}
