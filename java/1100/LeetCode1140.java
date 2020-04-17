public class LeetCode1140 {
    public int stoneGameII(int[] piles) {
        int[][] dp = new int[piles.length][piles.length];
        int[] sum = new int[piles.length];
        sum[piles.length - 1] = piles[piles.length - 1];
        for (int i = piles.length - 2;i >= 0;--i) {
            sum[i] = sum[i + 1] + piles[i];
        }
        helper(dp, 1, 0, sum);
        return dp[0][1];
    }

    /**
     * 当前选择在索引 (index，M) 处可以获得的最大值为
     * 1）可选择的 index + 2M 超过了剩余堆数，则全部取走
     * 2）否则选取下一手可获得的最小值，那必然是该种选择可获得的最大值 
     */
    public int helper(int[][] dp,int M,int index,int[] sum) {
        if (index >= dp.length) {
            return 0;
        }
        if (2 * M + index >= dp.length - 1) {
            return sum[index];
        }
        if (dp[index][M] != 0) {
            return dp[index][M];
        }
        int min = Integer.MAX_VALUE;
        // 如果当前函数求最大值，那么第二个人必然是最小值
        for (int X = 1;X <= 2 * M;++X) {
            min = Math.min(min, helper(dp,Math.max(M, X), index + X, sum));
        }
        dp[index][M] = sum[index] - min;
        return dp[index][M];
    } 
}