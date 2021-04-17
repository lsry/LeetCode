package L200;

public class LeetCode0264 {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int i = 0, j = 0, k = 0;
        for (int x = 1;x < n;++x) {
            int n2 = dp[i] * 2;
            int n3 = dp[j] * 3;
            int n5 = dp[k] * 5;
            dp[x] = Math.min(Math.min(n2, n3), n5);
            if (dp[x] == n2) {
                ++i;
            } 
            if (dp[x] == n3) {
                ++j;
            } 
            if (dp[x] == n5) {
                ++k;
            }
        }
        return dp[n - 1];
    }   
}
