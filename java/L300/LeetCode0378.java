package L300;

import java.util.PriorityQueue;

public class LeetCode0378 {
    /**
     * 优先队列合并
     */
    public int kthSmallest(int[][] matrix, int k) {
        final int N = matrix.length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });
        for (int i = 0;i < N;++i) {
            pq.offer(new int[]{matrix[0][i], 0, i});
        }
        while (!pq.isEmpty() && k != 1) {
            int[] arr = pq.poll();
            if (arr[1] < N - 1) {
                pq.offer(new int[]{matrix[arr[1] + 1][arr[2]], arr[1] + 1, arr[2]});
            }
            --k;
        }
        int[] res = pq.poll();
        return res[0];
    }
}