package L200;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0232 {}

class MyQueue {
    private Deque<Integer> in, out;

    /** Initialize your data structure here. */
    public MyQueue() {
        in = new LinkedList<>();
        out = new LinkedList<>();
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
        in.addFirst(x);
    }

    private void ensure() {
        if (out.size() == 0) {
            while (in.size() > 0) {
                out.addFirst(in.removeFirst());
            }
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        ensure();
        return out.removeFirst();
    }
    
    /** Get the front element. */
    public int peek() {
        ensure();
        return out.getFirst();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return in.size() == 0 && out.size() == 0;
    }
}