package L1000;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;

public class LeetCode1005{
    public int largestSumAfterKNegationsOld(int[] A, int K) {
        List<Integer> neg = new LinkedList<>();
        int min = Integer.MAX_VALUE;
        int sum = 0;
        for (int i : A){
            sum += i;
            if (i <= 0){
                neg.add(i);
            }
            if (i >= 0 && i < min){
                min = i;
            }
        }
        Collections.sort(neg);
        while (!neg.isEmpty() && K > 0){
            int pos = Math.abs(neg.remove(0));
            sum += 2 * pos;
            if (pos < min){
                min = pos;
            }
            K--;
        }
        while (K > 0){
            min = 0 - min;
            sum += 2 * min;
            K--;
        }
        return sum;
    }

    public int largestSumAfterKNegations(int[] nums, int k) {
        if (nums == null || nums.length == 0){
            return 0;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> Integer.compare(b, a));
        int sum = 0, min = Integer.MAX_VALUE;
        for (int num : nums) {
            if (num < 0) {
                pq.add(-num);
            } else {
                min = Math.min(min, num);
            }
            sum += num;
        }
        while (k > 0 && !pq.isEmpty()) {
            int cur = pq.poll();
            sum += 2 * cur;
            min = Math.min(min, cur);
            k--;

        }
        if (k > 0 && k % 2 == 1) {
            sum -= 2 * min;
        }
        return sum;
    }
}