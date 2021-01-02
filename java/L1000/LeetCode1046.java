package L1000;

import java.util.PriorityQueue;

public class LeetCode1046 {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((n1, n2) -> {
            return n2 - n1;
        });
        for (int stone : stones) {
            pq.offer(stone);
        }
        while (pq.size() > 1) {
            int w1 = pq.poll();
            int w2 = pq.poll();
            w1 = (w2 > w1) ? w2 - w1 : w1 - w2;
            if (w1 > 0) {
                pq.offer(w1);
            }
        }
        return pq.isEmpty() ? 0 : pq.poll();
    }
}
