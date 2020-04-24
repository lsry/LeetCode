import java.util.LinkedList;
import java.util.Queue;

public class LeetCode0200 {
    private int[][] indics = new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
    public int numIslands(char[][] grid) {
        int num = 0;
        for (int i = 0;i < grid.length;++i) {
            for (int j = 0;j < grid[0].length;++j) {
                if (grid[i][j] == '1') {
                    num++;
                    bfs(grid,i,j);
                }
            }
        }
        return num;
    }

    private void bfs(char[][] grid,int x,int y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x,y});
        grid[x][y] = '0';
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            for (int[] index : indics) {
                int nx = cur[0] + index[0];
                int ny = cur[1] + index[1];
                if (nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length && grid[nx][ny] == '1') {
                    queue.offer(new int[]{nx,ny});
                    grid[nx][ny] = '0';
                }
            }
        }
    }
}