public class LeetCode0887 {
    public int superEggDrop(int K, int N) {
        int[][] dp = new int[K + 1][N + 1];
        for (int i = 1;i <= N;++i) {
            dp[1][i] = i;
        }
        for (int i = 1;i <= K;i++) {
            dp[i][1] = 1;
        }
        for (int i = 2;i <= K;++i) {
            for (int j = 2;j <= N;++j) {
                int lo = 1, hi = j;
                while (lo + 1 < hi) {
                    int m = (lo + hi) / 2;
                    if (dp[i - 1][m - 1] < dp[i][j - m]) {
                        lo = m;
                    } else if (dp[i - 1][m - 1] > dp[i][j - m]) {
                        hi = m;
                    } else {
                        lo = hi = m;
                    }
                }
                dp[i][j] = 1 + Math.min(Math.max(dp[i - 1][lo - 1], dp[i][j - lo]),
                                        Math.max(dp[i - 1][hi - 1], dp[i][j - hi]));
            }
        } 
        return dp[K][N];
    }
}