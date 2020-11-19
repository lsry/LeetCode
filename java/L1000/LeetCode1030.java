package L1000;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode1030 {
    private static int[][] indics = new int[][]{{-1,0},{0,-1},{1,0},{0,1}};
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        boolean[][] flags = new boolean[R][C];
        int[][] res = new int[R * C][];
        int index = 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{r0,c0});
        flags[r0][c0] = true;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            res[index] = cur;
            ++index;
            for (int[] indic : indics) {
                int nx = cur[0] + indic[0];
                int ny = cur[1] + indic[1];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && !flags[nx][ny]) {
                    queue.offer(new int[]{nx , ny});
                    flags[nx][ny] = true;
                }
            }
        }
        return res;
    }
}
