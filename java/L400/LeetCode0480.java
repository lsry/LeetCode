package L400;

import java.util.HashMap;
import java.util.PriorityQueue;

public class LeetCode0480 {
    private class DupHeap {
        /**
         * small : 大根堆，维护左半边
         * large：小根堆，维护右半边
         */
        private PriorityQueue<Integer> small, large;
        private int k;
        private int smallSize, largeSize;
        private HashMap<Integer, Integer> delay;

        public DupHeap(int k) {
            this.k = k;
            large = new PriorityQueue<>((a, b) -> {
                return a.compareTo(b);
            });
            small = new PriorityQueue<>((a, b) -> {
                return b.compareTo(a);
            });
            this.smallSize = 0;
            this.largeSize = 0;
            delay = new HashMap<>();
        }

        private void prune(PriorityQueue<Integer> pq) {
            while (!pq.isEmpty()) {
                Integer ni = pq.peek();
                if (delay.containsKey(ni)) {
                    int freq = delay.get(ni) - 1;
                    if (freq == 0) {
                        delay.remove(ni);
                    } else {
                        delay.put(ni, freq);
                    }
                    pq.poll();
                } else {
                    break;
                }
            }
        }

        private void makeBalance() {
            if (smallSize > largeSize + 1) {
                large.offer(small.poll());
                ++largeSize;
                --smallSize;
                prune(small);
            } else if (smallSize < largeSize) {
                small.offer(large.poll());
                ++smallSize;
                --largeSize;
                prune(large);
            }
        }

        public void insert(int num) {
            if (small.isEmpty() || num <= small.peek()) {
                small.offer(num);
                ++smallSize;
            } else {
                large.offer(num);
                ++largeSize;
            }
            makeBalance();
        }

        public void erase(int num) {
            delay.put(num, delay.getOrDefault(num, 0) + 1);
            if (num <= small.peek()) {
                --smallSize;
                prune(small);
            } else {
                --largeSize;
                prune(large);
            }
            makeBalance();
        }

        public double getMedian() {
            if (k % 2 == 0) {
                return ((double)small.peek() + (double)large.peek()) / 2.0;
            } else {
                return small.peek() * 1.0;
            }
        }
    }
    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] res = new double[nums.length - k + 1];
        DupHeap dupHeap = new DupHeap(k);
        for (int i = 0;i < k;++i) {
            dupHeap.insert(nums[i]);
        }
        res[0] = dupHeap.getMedian();
        for (int i = k;i < nums.length;++i) {
            dupHeap.insert(nums[i]);
            dupHeap.erase(nums[i - k]);
            res[i - k] = dupHeap.getMedian();
        }
        return res;
    }
}