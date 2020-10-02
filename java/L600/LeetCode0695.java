package L600;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode0695 {
    public int maxAreaOfIsland(int[][] grid) {
        int R = grid.length, C = grid[0].length;
        int maxArea = 0;
        Queue<int[]> suit = new LinkedList<>();
        int[][] indics = new int[][]{{0,-1},{-1,0},{1,0},{0,1}};
        for (int r = 0;r < R;++r) {
            for (int c = 0;c < C;++c) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    suit.offer(new int[]{r,c});
                    grid[r][c] = 0;
                    while (!suit.isEmpty()) {
                        int[] cur = suit.poll();
                        ++area;
                        for (int i = 0;i < indics.length;++i) {
                            int x = cur[0] + indics[i][0];
                            int y = cur[1] + indics[i][1];
                            if (x >= 0 && x < R && y >= 0 && y < C && grid[x][y] == 1) {
                                suit.offer(new int[]{x,y});
                                grid[x][y] = 0;
                            }
                        }
                    }
                    if (area > maxArea) {
                        maxArea = area;
                    }
                }
            }
        }
        return maxArea;
    } // [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
}