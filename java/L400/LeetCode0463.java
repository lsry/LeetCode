package L400;

public class LeetCode0463 {
    private int circumference;
    private int M, N;
    public int islandPerimeter(int[][] grid) {
        circumference = 0;
        if (grid == null) {
            return circumference;
        }
        M = grid.length;
        N = grid[0].length;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (grid[i][j] == 1) {
                    dfs(grid,i,j);
                    return circumference;
                }
                
            }
        }
        return 0;
    }
    private void dfs(int[][] grid, int x, int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || grid[x][y] == 0) {
            return;
        }
        circumference += 4;
        grid[x][y] = -1;
        if (x - 1 >= 0 && grid[x - 1][y] != 0) {
            circumference -= 1;
            if (grid[x - 1][y] == 1) {
                dfs(grid,x - 1, y);
            }
            
        }
        if (x + 1 < M && grid[x + 1][y] != 0) {
            circumference -= 1;
            if (grid[x + 1][y] == 1) {
                dfs(grid,x + 1, y);
            }
            
        }
        if (y - 1 >= 0 && grid[x][y - 1] != 0) {
            circumference -= 1;
            if (grid[x][y - 1] == 1) {
                dfs(grid,x, y - 1);
            }
            
        }
        if (y + 1 < N && grid[x][y + 1] != 0) {
            circumference -= 1;
            if (grid[x][y + 1] == 1) {
                dfs(grid,x, y + 1);
            }
            
        }
    }
}
