public class LeetCode0329 {
    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int[][] dp = new int[matrix.length][matrix[0].length];
        int max = 1;
        for (int i = 0;i < matrix.length;++i) {
            for (int j = 0;j < matrix[0].length;++j) {
                if (dp[i][j] != 0) {
                    max= Math.max(max, dp[i][j]);
                } else {
                    max = Math.max(max, path(matrix, dp, i, j));
                }
            }
        }
        return max;
    }

    public int path(int[][] matrix,int[][] dp, int x, int y) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        } 
        dp[x][y] = 1;
        if (check(matrix,matrix[x][y],x - 1,y)) {
            dp[x][y] = Math.max(dp[x][y], 1 + path(matrix, dp, x - 1, y));
        }
        if (check(matrix, matrix[x][y], x, y - 1)) {
            dp[x][y] = Math.max(dp[x][y], 1 + path(matrix, dp, x, y - 1));
        }
        if (check(matrix, matrix[x][y], x, y + 1)) {
            dp[x][y] = Math.max(dp[x][y], 1 + path(matrix, dp, x, y + 1));
        }
        if (check(matrix, matrix[x][y], x + 1, y)) {
            dp[x][y] = Math.max(dp[x][y], 1 + path(matrix, dp, x + 1, y));
        }
        return dp[x][y];
    }

    public boolean check(int[][] matrix, int value, int x, int y) {
        return x >= 0 && x < matrix.length && y >= 0 && y < matrix[0].length && matrix[x][y] > value;
    }
}