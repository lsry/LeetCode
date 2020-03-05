import java.util.LinkedList;
import java.util.Queue;

public class LeetCode0225{}

class MyStack {

    private Queue<Integer> in;
    private Queue<Integer> out;
    private int top;

    public MyStack() {
        in = new LinkedList<>();
        out = new LinkedList<>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        in.offer(x);
        top = x;
    }
    
    /** 
     * Removes the element on top of the stack and returns that element. 
     * 由于弹出的元素在队列末尾，那么需要将其他的元素进入到另外一个队列中，然后将该元素弹出
     * 另外队列中最后进入的为当前栈的顶部 
     */
    public int pop() {
        int t = top;
        while (in.size() > 1) {
            top = in.poll();
            out.offer(top);
        }
        in.poll();
        Queue<Integer> temp = in;
        in = out;
        out = temp;
        return t;
    }
    
    /** Get the top element. */
    public int top() {
        return top;
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
        return out.isEmpty() && in.isEmpty();
    }
}