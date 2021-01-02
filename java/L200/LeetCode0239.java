package L200;

import java.util.PriorityQueue;

public class LeetCode0239 {
    public int[] maxSlidingWindowTLE(int[] nums, int k) {
        final int N = nums.length;
        int[] res = new int[N - k + 1];
        int index = 0;
        int max = nums[0];
        int i = -1, j = 0;
        while (j < N && j - i < k) {
            ++j;
            if (nums[j] > max) {
                max = nums[j];
            }
        }
        res[index] = max;
        ++index;
        for (j = j + 1;j < N;++j) {
            ++i;
            if (nums[j] >= max) {
                max = nums[j];
            } else if (nums[i] >= max) {
                max = Integer.MIN_VALUE;
                for (int p = i + 1;p <= j;++p) {
                    if (nums[p] > max) {
                        max = nums[p];
                    }
                }
            }
            res[index] = max;
            ++index;
        }
        return res;
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
        final int N = nums.length;
        int[] res = new int[N - k + 1];
        int index = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>((i1, i2) -> {
            return nums[i2] - nums[i1];
        });
        int i = 0, j = 0;
        for (;j < k;++j) {
            pq.offer(j);
        }
        res[index] = nums[pq.peek()];
        ++index;
        for (j = j + 1;j < N;++j) {
            pq.offer(j);
            ++i;
            while (!pq.isEmpty() && (pq.peek() < i || pq.peek() > j)) {
                pq.poll();
            }
            res[index] = nums[pq.peek()];
            ++index;
        }
        return res;
    }
}
