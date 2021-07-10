package L1800;

import java.util.Arrays;

public class LeetCode1833 {
    public int maxIceCreamPackage(int[] costs, int coins) {
        int[] dp = new int[coins + 1];
        for (int cost : costs) {
            for (int m = coins;m >= cost;--m) {
                dp[m] = Math.max(dp[m], dp[m - cost] + 1);
            }
        }
        return dp[coins];
    }

    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int ans = 0;
        int fee = 0;
        for (int cost : costs) {
            if (cost + fee <= coins) {
                ++ans;
                fee += cost;
            } else {
                break;
            }
        }
        return ans;
    }
}