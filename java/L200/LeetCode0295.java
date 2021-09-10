package L200;

import java.util.PriorityQueue;

public class LeetCode0295 {}

class MedianFinder {

    private PriorityQueue<Integer> left;
    private PriorityQueue<Integer> right;
    private int size;

    /** initialize your data structure here. */
    public MedianFinder() {
        left = new PriorityQueue<>((a, b) -> {
            return a >= b ? -1 : 1;
        });
        right = new PriorityQueue<>((a, b) -> {
            return a <= b ? -1 : 1;
        });
        size = 0;
    }
    
    public void addNum(int num) {
        ++size;
        if (left.isEmpty() && right.isEmpty()) {
            left.offer(num);
        } else if (left.isEmpty()) {
            if (num < right.peek()) {
                left.offer(num);
            } else {
                right.offer(num);
            }
        } else {
            if (num > left.peek()) {
                right.offer(num);
            } else {
                left.offer(num);
            }
        }
        if (left.size() - right.size() >= 2) {
            right.offer(left.poll());
        } else if (right.size() - left.size() >= 2) {
            left.offer(right.poll());
        }
    }
    
    public double findMedian() {
        if (size % 2 != 0) {
            return left.size() > right.size() ? left.peek() : right.peek();
        } else {
            int a = left.peek();
            int b = right.peek();
            return (a + b) / 2.0;
        }
    }
}