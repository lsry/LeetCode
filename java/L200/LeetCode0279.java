package L200;

import java.util.Arrays;

/**
 * 考虑 dp[j] 代表数字 j 所需的最小平方数的个数
 * 可以遍历从小到大的每一个平方数 x，那么情况有：
 * 1. 不需要当前平方数而产生的最小平方数   
 * 2. 使用当前平方数，就是 j 去掉当前平方数的最小加 1；   
 * dp[j] = min(dp[j], 1 + dp[j - x])
 */
public class LeetCode0279 {
    public int numSquaresRecur(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0; dp[1] = 1;
        for (int i = 2;i <= n;i++){
            dp[i] = -1;
        }
        return helper(dp, n);
    }

    private int helper(int[] dp,int n){
        if (dp[n] != -1){
            return dp[n];
        } 
        int sqrt = (int) Math.sqrt(n);
        if (sqrt * sqrt == n){
            dp[n] = 1;
            return 1;
        }
        int min = Integer.MAX_VALUE;
        // 优化点：只用遍历每一个平方数即可
        for (int i = 1;i * i <= n / 2;i++){
            int num = 1 + helper(dp, n - i * i);
            if (num < min){
                min = num;
            }
        }
        dp[n] = min;
        return min;
    }

    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 1;i * i <= n;++i) {
            for (int j = i * i;j <= n;++j) {
                dp[j] = Math.min(dp[j], 1 + dp[j - i * i]);
            }
        }
        return dp[n];
    }
}