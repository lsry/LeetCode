package L1400;

public class LeetCode1449 {
    public String largestNumber(int[] cost, int target) {
        String[] dp = new String[target + 1];
        dp[0] = "";
        for (int i = 1;i <= target;++i) {
            for (int j = 1;j <= 9;++j) {
                if (cost[j - 1] <= i) {
                    String s = dp[i - cost[j - 1]] == null ? null : String.valueOf(j)+ dp[i - cost[j - 1]];
                    if (s != null && (dp[i] == null || compare(s, dp[i]) > 0)) {
                        dp[i] = s;
                    }
                }
            }
        }
        return dp[target] == null ? "0" : dp[target];
    }

    private int compare(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return s1.length() - s2.length();
        } else {
            return s1.compareTo(s2);
        }
    }
}
