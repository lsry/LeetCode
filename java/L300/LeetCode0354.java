package L300;

import java.util.Arrays;

public class LeetCode0354 {
    public int maxEnvelopes(int[][] envelopes) {
        final int N = envelopes.length;
        if (N < 2) {
            return N;
        }
        Arrays.sort(envelopes, (a, b) -> {
            return a[0] == b[0] ? a[1] - b[1] : a[0] - b[0];
        });
        int[] dp = new int[N];
        int ans = 1;
        for (int i = 0;i < N;++i) {
            dp[i] = 1;
            for (int j = i - 1;j >= 0;--j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                } 
            }
            ans = Math.max(dp[i], ans);
        }
        return ans;
    }
}
