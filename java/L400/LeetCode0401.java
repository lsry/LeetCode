package L400;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0401 {
    private static final int[] times = new int[]{8,4,2,1,32,16,8,4,2,1};
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> res = new ArrayList<>();
        trace(turnedOn, 0, 0, 0, 0, res);
        return res;
    }

    private void trace(int turnedOn, int onCount, int index, int hour, int minute, List<String> res) {
        if (onCount == turnedOn) {
            res.add(timeToString(hour, minute));
            return;
        }
        for (int i = index;i < 10;++i) {
            if (i <= 3) {
                hour += times[i];
                if (hour <= 11) {
                    trace(turnedOn, onCount + 1, i + 1, hour, minute, res);
                }
                hour -= times[i];
            } else {
                minute += times[i];
                if (minute <= 59) {
                    trace(turnedOn, onCount + 1, i + 1, hour, minute, res);
                }
                minute -= times[i];
            }
        }
    }

    private String timeToString(int hour, int minute) {
        StringBuilder sb = new StringBuilder();
        sb.append(hour);
        sb.append(":");
        if (minute < 10) {
            sb.append('0');
        }
        sb.append(minute);
        return sb.toString();
    }

    public static void main(String[] args) {
        LeetCode0401 code = new LeetCode0401();
        code.readBinaryWatch(1);
    }
}
