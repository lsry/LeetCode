package L500;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode0542 {
    public int[][] updateMatrix(int[][] matrix) {
        int R = matrix.length, C = matrix[0].length;
        boolean[][] visits = new boolean[R][C];
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0;i < R;++i) {
            for (int j = 0;j < C;++j) {
                if (matrix[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                    visits[i][j] = true;
                }
            }
        }
        int[][] indics = new int[][]{{-1,0},{0,-1},{1,0},{0,1}};
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int[] index : indics) {
                int cx = cur[0] + index[0];
                int cy = cur[1] + index[1];
                if (cx >= 0 && cx < R && cy >= 0 && cy < C && visits[cx][cy] == false) {
                    matrix[cx][cy] = matrix[cur[0]][cur[1]] + 1;
                    visits[cx][cy] = true;
                    queue.offer(new int[]{cx,cy});
                }
            }
        }
        return matrix;
    }
}