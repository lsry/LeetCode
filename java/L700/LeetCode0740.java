package L700;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LeetCode0740 {
    public int deleteAndEarn(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        HashMap<Integer,Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        final int N = map.size();
        int[][] nodes = new int[N][2];
        int i = 0;
        for (Map.Entry<Integer,Integer> entry : map.entrySet()) {
            nodes[i][0] = entry.getKey();
            nodes[i][1] = entry.getValue();
            ++i;
        }
        Arrays.sort(nodes, (a, b) -> {
            return a[0] - b[0];
        });
        int[] points = new int[N + 3]; // 代表当前位置可得到的最大点数
        points[3] = nodes[0][0] * nodes[0][1];
        for (i = 4;i < N + 3;++i) {
            if (nodes[i - 3][0] == nodes[i - 4][0] + 1) { // 数字相邻
                points[i] = Math.max(points[i - 2] +  + nodes[i - 3][0] * nodes[i - 3][1], points[i - 1]);
            } else {
                points[i] = points[i - 1] + nodes[i - 3][0] * nodes[i - 3][1];
            }
            
        }
        return Math.max(points[N + 2], points[N + 1]);
    }
}
