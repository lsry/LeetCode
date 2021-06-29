package L100;

import java.util.HashMap;
import java.util.Map;

public class LeetCode0149 {
    public int maxPoints(int[][] points) {
        int max = 0;
        for (int i = 0;i < points.length;++i) {
            Map<String,Integer> map = new HashMap<>();
            int curMax = 0;
            for (int j = 0;j < points.length;++j) {
                if (j != i) {
                    int y = points[j][1] - points[i][1];
                    int x = points[j][0] - points[i][0];
                    int k = gcd(y, x);
                    String key = String.valueOf(y / k) + "/" + String.valueOf(x / k);
                    map.put(key, map.getOrDefault(key, 0) + 1);
                    curMax = Math.max(curMax, map.get(key));
                }
            }
            max = Math.max(max, curMax + 1);
        }
        return max;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);

    }
}
