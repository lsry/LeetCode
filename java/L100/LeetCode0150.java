package L100;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0150 {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new LinkedList<>();
        for (String token : tokens) {
            if (token.equals("+")) {
                Integer a = stack.removeFirst();
                Integer b = stack.removeFirst();
                stack.addFirst(a + b);
            } else if (token.equals("-")) {
                Integer a = stack.removeFirst();
                Integer b = stack.removeFirst();
                stack.addFirst(b - a);
            } else if (token.equals("*")) {
                Integer a = stack.removeFirst();
                Integer b = stack.removeFirst();
                stack.addFirst(b * a);
            } else if (token.equals("/")) {
                Integer a = stack.removeFirst();
                Integer b = stack.removeFirst();
                stack.addFirst(b / a);
            } else {
                stack.addFirst(Integer.valueOf(token));
            }
        }
        return stack.getFirst();
    }
}
