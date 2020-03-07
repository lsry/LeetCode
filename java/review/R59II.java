import java.util.LinkedList;
import java.util.Queue;

public class R59II {
}

class MaxQueue {
    private Queue<Integer> queue;
    private int max;

    public MaxQueue() {
        queue = new LinkedList<>();
        max = Integer.MIN_VALUE;
    }
    
    public int max_value() {
        return queue.isEmpty() ? -1 : max;
    }
    
    public void push_back(int value) {
        if (value > max) {
            max = value;
        }
        queue.offer(value);
    }
    
    public int pop_front() {
        if (queue.isEmpty()) {
            return -1;
        }
        int res = queue.poll();
        if (res >= max) {
            max = Integer.MIN_VALUE;
            for (int size = queue.size();size > 0;--size) {
                int t = queue.poll();
                if (t > max) {
                    max = t;
                }
                queue.offer(t);
            }
        }
        return res;
    }
}