package L1300;

import java.util.PriorityQueue;

public class LeetCode1337 {
    public int[] kWeakestRows(int[][] mat, int k) {
        if (mat == null || mat.length ==  0) {
            return new int[0];
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>(k, (a, b) -> {
            if (a[0] != b[0]) {
                return b[0] - a[0];
            }
            return b[1] - a[1];
        });
        for (int i = 0;i < mat.length;++i) {
            int one = 0;
            for (int x : mat[i]) {
                if (x == 1) {
                    ++one;
                }
            }
            if (pq.size() < k) {
                pq.offer(new int[]{one, i});
            } else if (one < pq.peek()[0]) {
                pq.poll();
                pq.offer(new int[]{one, i});
            }
        }
        int[] res = new int[k];
        int i = k - 1;
        while (!pq.isEmpty()) {
            res[i] = pq.poll()[1];
            --i;
        }
        return res;
    }
}