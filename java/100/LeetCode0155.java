import java.util.ArrayDeque;
import java.util.Deque;

public class LeetCode0155{}

class MinStack {
    private int min;
    private Deque<Integer> stack;
    /** initialize your data structure here. */
    public MinStack() {
        stack = new ArrayDeque<>();
        min = Integer.MAX_VALUE;
    }
    
    public void push(int x) {
        if (x < min) {
            min = x;
        }
        stack.addFirst(x);
    }
    
    public void pop() {
        int cur = stack.removeFirst();
        if (stack.isEmpty()) {
            min = Integer.MAX_VALUE;
        } else if (cur == min) {
            min = Integer.MAX_VALUE;
            for (int x : stack) {
                if (x < min) {
                    min = x;
                }
            }
        }
    }
    
    public int top() {
        return stack.getFirst();
    }
    
    public int getMin() {
        return min;
    }
}