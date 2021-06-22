package L800;

public class LeetCode0877 {
    public boolean stoneGame(int[] piles) {
        final int N = piles.length;
        int[][] dp = new int[N][N];
        int sum = 0;
        for (int pile : piles) {
            sum += pile;
        }
        int x = stones(piles, 0, N - 1, dp);
        return x > sum - x;
    }

    private int stones(int[] piles, int left, int right, int[][] dp) {
        if (left > right) {
            return 0;
        } else if (left == right) {
            return piles[left];
        } else if (dp[left][right] != 0) {
            return dp[left][right];
        }
        dp[left][right] = Math.max(stones(piles, left + 1, right, dp) + piles[left], 
                                   stones(piles, left, right - 1, dp) + piles[right]);
        return dp[left][right];
    }
}
