package L1400;

import java.util.PriorityQueue;

public class LeetCode1438 {
    public int longestSubarray(int[] nums, int limit) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> {
            return b[0] - a[0];
        });
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });
        int len = 0;
        for (int i = 0, j = 0;j < nums.length;++j) {
            maxHeap.offer(new int[]{nums[j], j});
            minHeap.offer(new int[]{nums[j], j});
            while (i < j && maxHeap.peek()[0] - minHeap.peek()[0] > limit) {
                ++i;
                while (maxHeap.peek()[1] < i) {
                    maxHeap.poll();
                }
                while (minHeap.peek()[1] < i) {
                    minHeap.poll();
                }
            }
            len = Math.max(len, j - i + 1);
        }
        return len;
    }
}
