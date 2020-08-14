package L000;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0020 {
    public boolean isValid(String s) {
        Deque<Character> stack = new LinkedList<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '[' || c == '{') {
                stack.addFirst(c);
            } else if (c == ')') {
                if (!stack.isEmpty() && stack.getFirst() == '(') {
                    stack.removeFirst();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (!stack.isEmpty() && stack.getFirst() == '[') {
                    stack.removeFirst();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (!stack.isEmpty() && stack.getFirst() == '{') {
                    stack.removeFirst();
                } else {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}