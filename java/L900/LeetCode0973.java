package L900;

import java.util.Arrays;

public class LeetCode0973 {
    /**
     * 排序取前K个元素
     */
    public int[][] kClosestSort(int[][] points, int K) {
        int[][] result = new int[K][2];
        Arrays.sort(points,(x,y) -> {
            return (x[0] * x[0] + x[1] * x[1]) - (y[0] * y[0] + y[1] * y[1]);
        });
        for (int i = 0;i < K;i++){
            result[i][0] = points[i][0];
            result[i][1] = points[i][1];
        }
        return result;
    }

    public int[][] kClosest(int[][] points, int K) {
        return Arrays.stream(points).sorted((x,y) -> {
            return (x[0] * x[0] + x[1] * x[1]) - (y[0] * y[0] + y[1] * y[1]);
        }).limit(K).toArray(int[][]::new);
    }
}