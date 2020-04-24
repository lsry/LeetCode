package review;

import java.util.LinkedList;
import java.util.Queue;

public class R13 {
    public int movingCount(int m, int n, int k) {
        int[][] index = new int[][]{{-1,0},{0,-1},{1,0},{0,1}};
        int[][] panel = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();
        panel[0][0] = 1;
        queue.offer(new int[]{0,0});
        int count = 0;
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            if (axisSum(cur[0], cur[1]) > k) {
                continue;
            }
            ++count;
            for (int[] idx : index) {
                int nx = idx[0] + cur[0];
                int ny = idx[1] + cur[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && panel[nx][ny] != 1) {
                    queue.offer(new int[]{nx,ny});
                    panel[nx][ny] = 1;
                }
            }
        }
        return count;
    }

    private int axisSum(int x,int y) {
        int sum = 0;
        while (x != 0) {
            sum += x % 10;
            x /= 10;
        }
        while (y != 0) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }
}