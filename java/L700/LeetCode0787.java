package L700;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;

public class LeetCode0787 {
    /**
     * TLE
     */
    public int findCheapestPriceTLE(int n, int[][] flights, int src, int dst, int k) {
        HashMap<Integer, List<int[]>> map = new HashMap<>();
        for (int[] flight : flights) {
            List<int[]> list = map.getOrDefault(flight[0], new ArrayList<>());
            list.add(new int[]{flight[1], flight[2]});
            map.put(flight[0], list);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[2] - b[2];
        });
        pq.offer(new int[]{src, 0, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            if (cur[0] == dst) {
                return cur[2];
            }
            if (cur[1] > k) {
                continue;
            }
            List<int[]> list = map.get(cur[0]);
            if (list != null && !list.isEmpty()) {
                for (int[] arr : list) {
                    pq.offer(new int[]{arr[0], cur[1] + 1, cur[2] + arr[1]});
                }
            }
        }
        return -1;
    }

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        final int INF = 1_000_000_000;
        int[][] dist = new int[k + 2][n];
        for (int i = 0;i < k + 2;++i) {
            Arrays.fill(dist[i], INF);
        }
        dist[0][src] = 0;
        for (int t = 1;t < k + 2;++t) {
            for (int[] flight : flights) {
                dist[t][flight[1]] = Math.min(dist[t][flight[1]], dist[t - 1][flight[0]] + flight[2]);
            }
        }
        int ans = INF;
        for (int x = 0;x < k + 2;++x) {
            ans = Math.min(ans, dist[x][dst]);
        }
        return ans >= INF ? -1 : ans;
    }
}