public class LeetCode0063 {
    public int uniquePathsWithObstaclesTLE(int[][] obstacleGrid) {
        return ways(obstacleGrid, 0, 0);
    }
    private int ways(int[][] grid, int x, int y) {
        if (x >= grid.length || y >= grid[0].length) {
            return 0;
        } else if (grid[x][y] == 1) {
            return 0;
        } else if (x == grid.length - 1 && y == grid[0].length - 1) {
            return 1;
        } 
        return ways(grid, x + 1, y) + ways(grid, x, y + 1);
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        final int M = obstacleGrid.length, N = obstacleGrid[0].length;
        int[][] dp = new int[M][N];
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1;i < M;++i) {
            if (obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        for (int i = 1;i < N;++i) {
            if (obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
            } else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        for (int i = 1;i < M;++i) {
            for (int j = 1;j < N;++j) {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[M - 1][N - 1];
    }
}