package L700;

public class LeetCode0746 {
    public int minCostClimbingStairs(int[] cost) {
        if (cost == null || cost.length < 2) {
            return 0;
        }
        int[] dp = new int[2];
        for (int i = 2;i < cost.length;++i) {
            int v = Math.min(dp[0] + cost[i - 2], dp[1] + cost[i - 1]);
            dp[0] = dp[1];
            dp[1] = dp[v];
        }
        return Math.min(dp[0] + cost[cost.length - 2], dp[1] + cost[cost.length - 1]);
    }
}
