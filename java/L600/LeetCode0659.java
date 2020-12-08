package L600;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class LeetCode0659 {
    public boolean isPossible(int[] nums) {
        if (nums == null || nums.length < 3) {
            return false;
        }
        HashMap<Integer, PriorityQueue<Integer>> map = new HashMap<>();
        for (int num : nums) {
            PriorityQueue<Integer> pq = map.getOrDefault(num - 1, new PriorityQueue<Integer>());
            int t = 0;
            if (!pq.isEmpty()) {
                t = pq.poll();
            }
            PriorityQueue<Integer> pq2 = map.getOrDefault(num, new PriorityQueue<Integer>());
            pq2.offer(t + 1);
            map.put(num, pq2);
        }
        for (Map.Entry<Integer, PriorityQueue<Integer>> entry : map.entrySet()) {
            PriorityQueue<Integer> pq = entry.getValue();
            if (!pq.isEmpty() && pq.peek() < 3) {
                return false;
            }
        }
        return true;
    }
}
