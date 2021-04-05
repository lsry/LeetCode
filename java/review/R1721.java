package review;

import java.util.Deque;
import java.util.LinkedList;

public class R1721 {
    /**
     * 考虑每一个矩形 h 可接水的数目，取决于左边最大值 lm 和右边最大值 rm，max(min(rm, lm) - h, 0)
     * 维护右边最大值的一个单调递增栈
     */
    public int trap(int[] height) {
        if (height == null || height.length < 3) {
            return 0;
        }
        Deque<Integer> stack = new LinkedList<>();
        stack.addFirst(height.length - 1);
        for (int i = height.length - 2;i >= 0;--i) {
            if (!stack.isEmpty() && height[i] >= height[stack.getFirst()]) {
                stack.addFirst(i);
            }
        }
        int lm = 0;
        int ans = 0;
        for (int i = 1;i < height.length - 1;++i) {
            while (!stack.isEmpty() && stack.getFirst() <= i) {
                stack.removeFirst();
            }
            if (!stack.isEmpty()) {
                int h = Math.min(height[lm], height[stack.getFirst()]);
                ans += Math.max(h - height[i], 0);
            }
            if (height[i] >= height[lm]) {
                lm = i;
            }
        }
        return ans;
    }
}
