import java.util.ArrayList;
import java.util.List;

public class LeetCode0834 {
    private int[] ans;
    private int[] dp;
    private int[] sz;
    private List<List<Integer>> graph;
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        ans = new int[N];
        dp = new int[N];
        sz = new int[N];
        graph = new ArrayList<>(N);
        for (int i = 0;i < N;++i) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        return ans;
    }
    private void dfs1(int u, int f) {
        sz[u] = 1;
        for (int v : graph.get(u)) {
            if (v != f) {
                dfs1(v, u);
                dp[u] += dp[v] + sz[v];
                sz[u] += sz[v];
            }
        }
    }
    private void dfs2(int u, int f) {
        ans[u] = dp[u];
        for (int v : graph.get(u)) {
            if (v != f) {
                int pu = dp[u], pz = sz[u];
                int tv = dp[v], tz = sz[v];
                dp[u] = dp[u] - (dp[v] + sz[v]);
                sz[u] -= sz[v];
                dp[v] = dp[v] + (dp[u] + sz[u]);
                sz[v] += sz[u];
                dfs2(v, u);
                dp[u] = pu;
                sz[u] = pz;
                dp[v] = tv;
                sz[v] = tz;
            }
        }
    }
}