package L1000;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode1047 {
    public String removeDuplicates(String S) {       
        if (S == null || S.length() < 2) {
            return S;
        }
        final int N = S.length();
        Deque<Character> stack = new LinkedList<>();
        stack.addFirst(S.charAt(0));
        for (int i = 1;i < N;++i) {
            if (stack.size() > 0 && S.charAt(i) == stack.getFirst()) {
                stack.removeFirst();
            } else {
                stack.addFirst(S.charAt(i));
            }
        }
        StringBuilder res = new StringBuilder();
        while (stack.size() > 0) {
            res.append(stack.removeFirst());
        }
        return res.reverse().toString();
    }
}
