package L000;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0085 {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return 0;
        }
        final int M = matrix.length;
        final int N = matrix[0].length;
        int[] heights = new int[N];
        int ans = 0;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            int[] lefts = new int[N];
            int[] rights = new int[N];
            Deque<Integer> stack = new LinkedList<>();
            for (int j = 0;j < N;++j) {
                while (!stack.isEmpty() && heights[stack.getFirst()] >= heights[j]) {
                    stack.removeFirst();
                }
                lefts[j] = stack.isEmpty() ? -1 : stack.getFirst();
                stack.addFirst(j);
            }
            stack.clear();
            for (int j = N - 1;j >= 0;--j) {
                while (!stack.isEmpty() && heights[stack.getFirst()] >= heights[j]) {
                    stack.removeFirst();
                }
                rights[j] = stack.isEmpty() ? N : stack.getFirst();
                stack.addFirst(j);
            }
            for (int j = 0;j < N;++j) {
                ans = Math.max(ans, heights[j] * (rights[j] - lefts[j] - 1));
            }
        }
        return ans;
    }
}
