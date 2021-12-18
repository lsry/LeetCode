package L600;

import java.util.PriorityQueue;

public class LeetCode0689 {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        if (nums == null || nums.length  < k * 3) {
            return new int[0];
        }
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        int[] res = new int[]{1, k + 1, k * 2 + 1};
        int maxSum = sums[k * 3] -sums[0];
        int leftSum = sums[k] - sums[0], left = 1;
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            int s = (sums[b + k] - sums[b - 1]) - (sums[a + k] - sums[a - 1]);
            if (s == 0) {
                return a - b;
            } else {
                return s;
            }
        });
        for (int i = 2 * k + 1; i + k - 1 < sums.length;++i) {
            pq.offer(i);
        }
        for (int i = 1;3 * k + i < sums.length && !pq.isEmpty();++i) {
            int sm = sums[2 * k + i - 1] - sums[k + i - 1];
            int lm = sums[k + i - 1] - sums[i - 1];
            if (lm > leftSum) {
                leftSum = lm;
                left = i;
            }
            pq.remove(2 * k + i - 1);
            int id = pq.peek();
            int rm = sums[id + k - 1] - sums[id - 1];
            if (sm + leftSum + rm > maxSum) {
                res[0] = left;
                res[1] = i + k;
                res[2] = id;
                maxSum = sm + leftSum + rm;
            }
        }
        res[0] -= 1;
        res[1] -= 1;
        res[2] -= 1;
        return res;
    }
}
