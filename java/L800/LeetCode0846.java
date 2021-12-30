package L800;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class LeetCode0846 {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand == null || hand.length < groupSize || hand.length % groupSize != 0) {
            return false;
        }
        HashMap<Integer, Integer> counts = new HashMap<>();
        for (int h : hand) {
            counts.put(h, counts.getOrDefault(h, 0) + 1);
        }
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> {
            return a.getKey() - b.getKey();
        });
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            pq.offer(entry);
        }
        while (!pq.isEmpty()) {
            while (!pq.isEmpty() && pq.peek().getValue() == 0) {
                pq.poll();
            }
            if (pq.isEmpty()) {
                break;
            }
            Map.Entry<Integer, Integer> entry = pq.poll();
            int first = entry.getKey();
            entry.setValue(entry.getValue() - 1);
            if (entry.getValue() > 0) {
                pq.offer(entry);
            }
            for (int i = 1;i < groupSize;++i) {
                Integer next = counts.getOrDefault(first + i, null);
                if (next == null || next == 0) {
                    return false;
                }
                counts.put(first + i, next - 1);
            }
        }
        return true;
    }
}
