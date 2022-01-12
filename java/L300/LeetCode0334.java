package L300;

import java.util.PriorityQueue;

public class LeetCode0334 {
    public boolean increasingTriplet(int[] nums) {
        if (nums == null || nums.length < 3) {
            return false;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return Integer.compare(nums[b], nums[a]);
        });
        for (int i = nums.length - 1;i > 1;--i) {
            pq.offer(i);
        }
        int min = nums[0];
        for (int i = 1;i < nums.length - 1;++i) {
            while (!pq.isEmpty() && (pq.peek() <= i)) {
                pq.poll();
            }
            if (pq.isEmpty()) {
                break;
            }
            if (min < nums[i] && nums[i] < nums[pq.peek()]) {
                return true;
            }
            min = Math.min(min, nums[i]);
        }
        return false;
    }
}
