package L700;

public class LeetCode0718 {
    /**
     * 类似最长公共子串
     * f(i, j) = f(i - 1, j - 1) + 1 , A[i] = B[j];
     *         = 0 , A[i] != B[j]
     * @param A
     * @param B
     * @return
     */
    public int findLength(int[] A, int[] B) {
        if (A == null || A.length == 0 || B == null || B.length == 0) {
            return 0;
        }
        int max = 0;
        int[][] dp = new int[A.length + 1][B.length + 1];
        for (int i = 1;i <= A.length;++i) {
            for (int j = 1;j <= B.length;++j) {
                if (A[i - 1] == A[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > max) {
                        max = dp[i][j];
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return max;
    }
}