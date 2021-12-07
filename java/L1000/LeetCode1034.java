package L1000;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode1034 {
    private static final int[][] indics = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        final int M = grid.length, N = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{row, col});
        int originalColor = grid[row][col];
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int r = cur[0], c = cur[1];
            if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] != originalColor) {
                continue;
            }
            int count = 0;
            for (int[] indic : indics) {
                int nr = r + indic[0], nc = c + indic[1];
                if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                    if (grid[nr][nc] == originalColor) {
                        queue.offer(new int[]{nr, nc});
                    }
                    if (grid[nr][nc] == originalColor || grid[nr][nc] == -1 || grid[nr][nc] == -2) {
                        count++;
                    }
                }
            }
            grid[r][c] = count == 4 ? -1 : -2;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == -1) {
                    grid[i][j] = originalColor;
                } else if (grid[i][j] == -2) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
}
