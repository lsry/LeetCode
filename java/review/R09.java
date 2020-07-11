package review;

import java.util.Deque;
import java.util.LinkedList;

public class R09 {
}

class CQueue {
    private Deque<Integer> eqstack, exstack;

    public CQueue() {
        eqstack = new LinkedList<>();
        exstack = new LinkedList<>();
    }
    
    public void appendTail(int value) {
        eqstack.addFirst(value);
    }
    
    public int deleteHead() {
        if (exstack.isEmpty()) {
            while (!eqstack.isEmpty()) {
                exstack.addFirst(eqstack.removeFirst());
            }
        }
        return exstack.isEmpty() ? -1 : exstack.removeFirst();
    }
}