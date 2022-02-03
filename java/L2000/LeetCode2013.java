package L2000;

import java.util.HashMap;
import java.util.Map;

public class LeetCode2013 {}

class DetectSquares {

    private HashMap<Integer, Integer> points;

    private int toOne(int x, int y) {
        return x * 10000 + y;
    }

    private int[] toPoint(int num) {
        return new int[]{num / 10000, num % 10000};
    }

    public DetectSquares() {
        points = new HashMap<>();
    }
    
    public void add(int[] point) {
        int num = toOne(point[0], point[1]);
        points.put(num, points.getOrDefault(num, 0) + 1);
    }
    
    public int count(int[] point) {
        int total = 0;
        for (Map.Entry<Integer, Integer> entry : points.entrySet()) {
            int[] op = toPoint(entry.getKey());
            if (entry.getValue() > 0 
                && op[0] != point[0] && op[1] != point[1] 
                && Math.abs(op[0] - point[0]) == Math.abs(op[1] - point[1])) {
                int p1 = toOne(op[0], point[1]);
                int p2 = toOne(point[0], op[1]);
                int p1m = points.getOrDefault(p1, 0);
                int p2m = points.getOrDefault(p2, 0);
                total += p1m * p2m * entry.getValue();
            }
        }
        return total;
    }
}