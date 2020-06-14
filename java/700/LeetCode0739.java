import java.util.Stack;

public class LeetCode0739{
    /**
     * 单调递减栈
     */
    public int[] dailyTemperatures(int[] T) {
        if (T == null || T.length <= 0){
            return new int[]{};
        }
        int[] arr = new int[T.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0;i < T.length;i++){
            if (stack.empty()){
                stack.push(i);
            } else {
                // 栈中元素小于当前元素，出栈，并设置对应的天数
                while (!stack.empty() && T[i] > T[stack.peek()]){
                    int x = stack.pop();
                    arr[x] = i - x;
                }
                stack.push(i);
            }
        }
        return arr;
    }

    public static void main(String[] args) {
        
    }
}