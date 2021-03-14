package L500;

import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0503 {
    public int[] nextGreaterElements(int[] nums) {
        final int N = nums.length;
        int[] res = new int[N];
        Arrays.fill(res, -1);
        Deque<Integer> stack = new LinkedList<>();
        for (int i = 0;i < 2 * N - 1;++i) {
            while (!stack.isEmpty() && nums[i % N] > nums[stack.getFirst() % N]) {
                int index = stack.removeFirst();
                res[index % N] = nums[i % N];
            }
            stack.addFirst(i);
        }
        return res;
    }
}
