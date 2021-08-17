package L500;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0576 {
    private static final int MOD = 1_000_000_007;
    private static final int[][] dirs = new int[][]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) {
            return 0;
        }
        int[][][] dp = new int[m][n][maxMove + 1];
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                for (int k = 0;k <= maxMove;++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return recur(m, n, maxMove, startRow, startColumn, dp);
    }

    private int recur(int m, int n, int maxMove, int startRow, int startColumn, int[][][] dp) {
        if (startRow < 0 || startColumn < 0 || startRow >= m || startColumn >= n) {
            return 1;
        }
        if (maxMove <= 0) {
            return 0;
        }
        if (dp[startRow][startColumn][maxMove] != -1) {
            return dp[startRow][startColumn][maxMove];
        }
        long ans = 0;
        for (int[] dir : dirs) {
            int nx = startRow + dir[0];
            int ny = startColumn + dir[1];
            ans = (ans + recur(m, n, maxMove - 1, nx, ny, dp)) % MOD;
        }
        dp[startRow][startColumn][maxMove] = (int)ans;
        return dp[startRow][startColumn][maxMove];
    }

    /**
     * Time Linmit Exceed
     */
    public int findPathsTLE(int m, int n, int maxMove, int startRow, int startColumn) {
        long ans = 0;
        Deque<int[]> qu = new LinkedList<>();
        qu.offer(new int[]{startRow, startColumn});
        int step = 0;
        while (!qu.isEmpty() && step < maxMove) {
            int sz = qu.size();
            for (int i = 0;i < sz;++i) {
                int[] cur = qu.poll();
                long r = 0;
                for (int[] dir : dirs) {
                    int nx = cur[0] + dir[0];
                    int ny = cur[1] + dir[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        r = (r + 1) % MOD;
                    } else {
                        qu.offer(new int[]{nx, ny});
                    }
                }
                ans = (ans + r) % MOD;
            }
            ++step;
        }
        return (int)ans;
    }
}