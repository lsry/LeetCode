package L700;

import java.util.PriorityQueue;

public class LeetCode0703 {}

class KthLargest {
    private PriorityQueue<Integer> pq;
    private int K;

    public KthLargest(int k, int[] nums) {
        this.K = k;
        this.pq = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a, b);
        });
        for (int i = 0;i < nums.length;++i) {
            if (i < K) {
                pq.offer(nums[i]);
            } else if (nums[i] > pq.peek()) {
                pq.poll();
                pq.offer(nums[i]);
            }
        }
    }
    
    public int add(int val) {
        if (pq.size() < K) {
            pq.offer(val);
        } else if (val > pq.peek()) {
            pq.poll();
            pq.offer(val);
        }
        return pq.peek();
    }
}
