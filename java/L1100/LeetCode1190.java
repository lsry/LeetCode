package L1100;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode1190 {
    public String reverseParentheses(String s) {
        if (s == null || s.length() < 2) {
            return s;
        }
        char[] cs = s.toCharArray();
        final int N = s.length();
        Deque<Integer> stack = new LinkedList<>();
        for (int i = 0;i < N;++i) {
            if (cs[i] == '(') {
                stack.addFirst(i);
            } else if (cs[i] == ')') {
                int left = stack.removeFirst() + 1;
                int right = i - 1;
                while (left < right) {
                    char t = cs[left];
                    cs[left] = cs[right];
                    cs[right] = t;
                    ++left;
                    --right;
                }
            }
        }
        StringBuilder sBuilder = new StringBuilder();
        for (char c : cs) {
            if (c >= 'a' && c <= 'z') {
                sBuilder.append(c);
            }
        }
        return sBuilder.toString();
    }
}
