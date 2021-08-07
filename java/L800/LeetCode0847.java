package L800;

import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0847 {
    private static final int INF = 0x3f3f3f3f;
    public int shortestPathLength(int[][] graph) {
        if (graph == null || graph.length == 0) {
            return 0;
        }
        final int N = graph.length;
        int mask = 1 << N;
        int[][] dist = new int[mask][N];
        for (int i = 0;i < mask;++i) {
            Arrays.fill(dist[i], INF);
        }
        Deque<int[]> queue = new LinkedList<>();
        for (int i = 0;i < N;++i) {
            dist[1 << i][i] = 0;
            queue.offer(new int[]{1 << i, i});
        }
        while (!queue.isEmpty()) {
            int[] node = queue.poll();
            int state = node[0], u = node[1], step = dist[state][u];
            if (state == mask - 1) {
                return step;
            }
            for (int n : graph[u]) {
                int new_state = state | (1 << n);
                if (dist[new_state][n] == INF || dist[new_state][n] > step + 1) {
                    dist[new_state][n] = step + 1;
                    queue.offer(new int[]{new_state, n});
                }
            }
        }
        return -1;
    }
}