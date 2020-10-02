package L600;

import java.util.PriorityQueue;
import java.util.List;

public class LeetCode0632 {
    public int[] smallestRange(List<List<Integer>> nums) {
        int[] range = new int[]{-1000000,1000000};
        int[] next = new int[nums.size()];
        PriorityQueue<Integer> pq = new PriorityQueue<>((index1,index2) -> {
            return nums.get(index1).get(next[index1]) - nums.get(index2).get(next[index2]);
        });
        int max = Integer.MIN_VALUE;
        for (int i = 0;i < nums.size();++i) {
            pq.offer(i);
            if (nums.get(i).get(next[i]) > max) {
                max = nums.get(i).get(next[i]);
            }
        }
        while (true) {
            int minArr = pq.poll();
            int minVal = nums.get(minArr).get(next[minArr]);
            if ((max - minVal < range[1] - range[0]) || (max - minVal == range[1] - range[0] && minVal < range[0])) {
                range[0] = minVal;
                range[1] = max;
            }
            next[minArr]++;
            if (next[minArr] >= nums.get(minArr).size()) {
                break;
            }
            if (nums.get(minArr).get(next[minArr]) > max) {
                max = nums.get(minArr).get(next[minArr]);
            }
            pq.offer(minArr);
        }
        return range;
    }
}