package L1500;

import java.util.HashMap;

public class LeetCode1583 {
    public int unhappyFriends(int n, int[][] preferences, int[][] pairs) {
        int[][] ranks = new int[n][n];
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < preferences[i].length;++j) {
                ranks[i][preferences[i][j]] = j;
            }
        }
        HashMap<Integer,Integer> pairMap = new HashMap<>();
        for (int[] pair : pairs) {
            pairMap.put(pair[0], pair[1]);
            pairMap.put(pair[1], pair[0]);
        }
        int ans = 0;
        for (int[] pair : pairs) {
            for (int x : pair) {
                int y = pairMap.get(x);
                for (int i = 0;i < preferences[x].length;++i) {
                    if (preferences[x][i] == y) {
                        break;
                    }
                    int u = preferences[x][i];
                    int v = pairMap.get(u);
                    if (ranks[x][u] < ranks[x][y] && ranks[u][x] < ranks[u][v]) {
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
}