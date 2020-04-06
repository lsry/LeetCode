import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0042{
    /**
     * 对于每一个位置，能积水的容量是左边最大值与右边最大值的最小那个和当前高度的差(找左右两边最大值中小者，减去本身高度)
     * 如果数组递减排列，则时间退化到 O(n^2)
     */
    public int trapDP(int[] height) {
        // 数组最小应该有三个元素
        if (height == null || height.length <= 2){
            return 0;
        }
        int sum = 0;
        int right = 0; // 右边最大值所在位置
        int leftmax = height[0],rightmax = 0;
        for (int i = 1;i < height.length - 1;i++){
            // 求左边最大高度
            if (height[i] > leftmax){
                leftmax = height[i];
            }
            // 只有当前位置越过此时右边最大高度所在位置时，才寻找右边最大高度
            if (right <= i){
                rightmax = 0;
                for (int j = i + 1;j < height.length;j++){
                    if (height[j] >= rightmax){
                        right = j;
                        rightmax = height[j];
                    }
                }
            }
            // 当前位置能积水，起码比左右最大高度小
            if (leftmax > height[i] && rightmax > height[i]){
                sum += Math.min(leftmax, rightmax) - height[i];
            }
        }
        return sum;
    }

    /**
     * 单调递减栈
     * 若出现一个数字height[x1]大于栈顶元素height[x]，则代表可以接水
     * 那寻找栈中大于height[x]的元素height[x0]
     * 则结果 (min(height[x1],height[x0]) - height[x]) * (x1 - x0 -1)
     */
    public int trap(int[] height) {
        if (height == null) {
            return 0;
        }
        int ans = 0;
        Deque<Integer> stack = new LinkedList<>();
        for (int i = 0;i < height.length;++i) {
            while (!stack.isEmpty() && height[i] > height[stack.getFirst()]) {
                int cur = stack.getFirst();
                while (!stack.isEmpty() && height[stack.getFirst()] == height[cur]) {
                    stack.removeFirst();
                }
                if (!stack.isEmpty()) {
                    ans += (Math.min(height[i], height[stack.getFirst()]) - height[cur]) * (i - stack.getFirst() - 1);
                }
            }
            stack.addFirst(i);
        }
        return ans;
    }

    public static void main(String[] args) {
        LeetCode0042 l42 = new LeetCode0042();
        System.out.println("6 :" + l42.trap(new int[]{0,1,0,2,1,0,1,3,2,1,2,1}));
        System.out.println("2 :" + l42.trap(new int[]{2,0,2}));
        System.out.println("1 :" + l42.trap(new int[]{4,2,3}));
    }
}