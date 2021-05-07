package L1400;

public class LeetCode1473 {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int[][][] dp = new int[m + 1][n][target + 1];
        for (int i = 0;i <= m;++i) {
            for (int j = 0;j < n;++j) {
                for (int k = 0;k <= target;++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        for (int j = 0;j < n;++j) {
            dp[0][j][0] = 0;
        }
        // 如何形成 k 个街区？
        // 1. 之前已经形成 k 个街区，此时用和前一家相同颜色
        // 2. 之前已经形成 k-1 个街区，此时用和前一家不同颜色
        for (int i = 1;i <= m;++i) {
            if (houses[i - 1] != 0) {
                for (int k = 1;k <= target;++k) {
                    dp[i][houses[i - 1] - 1][k] = dp[i - 1][houses[i - 1] - 1][k];
                    int c = -1;
                    for (int j = 0;j < n;++j) { // 判断用其他颜色形成 k-1 个街区时的最小花费，此时用不同颜色即可形成 k 个街区
                        if (dp[i - 1][j][k - 1] != -1 && j != houses[i - 1] - 1) {
                            if (c == -1) {
                                c = dp[i - 1][j][k - 1];
                            } else {
                                c = Math.min(c, dp[i - 1][j][k - 1]);
                            }
                        }
                    }
                    if (c != -1) {
                        if (dp[i][houses[i - 1] - 1][k] == -1) {
                            dp[i][houses[i - 1] - 1][k] = c;
                        } else {
                            dp[i][houses[i - 1] - 1][k] = Math.min(dp[i][houses[i - 1] - 1][k], c);
                        }
                    }
                }
            } else {
                for (int j = 0;j < n;++j) {
                    for (int k = 1;k <= target;++k) {
                        dp[i][j][k] = dp[i - 1][j][k] == -1 ? -1 : dp[i - 1][j][k] + cost[i - 1][j];
                        int c = -1;
                        for (int x = 0;x < n;++x) {
                            if (dp[i - 1][x][k - 1] != -1 && x != j) {
                                if (c == -1) {
                                    c = dp[i - 1][x][k - 1];
                                } else {
                                    c = Math.min(c, dp[i - 1][x][k - 1]);
                                }
                            }
                        }
                        if (c != -1) {
                            if (dp[i][j][k] == -1) {
                                dp[i][j][k] = c + cost[i - 1][j];
                            } else {
                                dp[i][j][k] = Math.min(dp[i][j][k], c + cost[i - 1][j]);
                            }
                        }
                    }
                }
            }
        }
        int min = -1;
        for (int j = 0;j < n;++j) {
            if (dp[m][j][target] != -1) {
                if (min == -1) {
                    min = dp[m][j][target];
                } else {
                    min = Math.min(min, dp[m][j][target]);
                }
            }
        }
        return min;
    }
}
