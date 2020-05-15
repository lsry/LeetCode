public class LeetCode0983 {
    public int mincostTickets(int[] days, int[] costs) {
        int[][] dp = new int[days.length][3];
        return helper(days, costs, dp, 0, 0);
    }
    public int helper(int[] days,int[] costs,int[][] dp,int index,int cost) {
        if (index >= days.length) {
            return cost;
        }
        if (dp[index][0] == 0) {
            dp[index][0] = helper(days, costs, dp, index + 1, costs[0]);
        }
        if (dp[index][1] == 0) {
            int newi = index;
            for (;newi < days.length && days[newi] < days[index] + 7;++newi);
            dp[index][1] = helper(days, costs, dp, newi, costs[1]);
        }
        if (dp[index][2] == 0){
            int newi = index;
            for (;newi < days.length && days[newi] < days[index] + 30;++newi);
            dp[index][2] = helper(days, costs, dp, newi, costs[2]);
        }
        int daycost = Math.min(dp[index][0], Math.min(dp[index][1], dp[index][2]));
        return daycost + cost;
    }
}