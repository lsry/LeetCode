package L500;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class LeetCode0514 {
    public int findRotateSteps(String ring, String key) {
        final int RN = ring.length();
        final int KN = key.length();
        List<List<Integer>> chps = new ArrayList<>(26);
        for (int i = 0;i < 26;++i) {
            chps.add(new ArrayList<>());
        }
        for (int i = 0;i < RN;++i) {
            chps.get(ring.charAt(i) - 'a').add(i);
        }
        int[][] dp = new int[KN][RN];
        for (int i = 0;i < dp.length;++i) {
            Arrays.fill(dp[i], 0x3f3f3f3f);
        }
        List<Integer> cp = chps.get(key.charAt(0) - 'a');
        for (int i : cp) {
            dp[0][i] = Math.min(i, RN - i);
        }
        
        for (int i = 1;i < KN;++i) {
            for (int j : chps.get(key.charAt(i) - 'a')) {
                for (int k : chps.get(key.charAt(i - 1) - 'a')) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k] + Math.min(Math.abs(j - k), RN - Math.abs(j - k)));
                }
            }
        }
        return Arrays.stream(dp[KN - 1]).min().getAsInt() + KN;
    }
}
