import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0084 {
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0) {
            return 0;
        }
        final int N = heights.length;
        Deque<Integer> stack = new LinkedList<>();
        int[] lefts = new int[N];
        for (int i = 0;i < N;++i) {
            while (!stack.isEmpty() && heights[stack.getFirst()] >= heights[i]) {
                stack.removeFirst();
            }
            lefts[i] = stack.isEmpty() ? -1 : stack.getFirst();
            stack.addFirst(i);   
        }
        stack.clear();
        int[] rights = new int[N];
        for (int i = N - 1;i >= 0;--i) {
            while (!stack.isEmpty() && heights[stack.getFirst()] >= heights[i]) {
                stack.removeFirst();
            }
            rights[i] = stack.isEmpty() ? N : stack.getFirst();
            stack.addFirst(i);
        }
        int ans = 0;
        for (int i = 0;i < N;++i) {
            ans = Math.max(ans, (rights[i] - lefts[i] - 1) * heights[i]);
        }
        return ans;
    }
}