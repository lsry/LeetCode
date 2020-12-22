package L300;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0316 {
    public String removeDuplicateLetters(String s) {
        Deque<Character> stack = new LinkedList<>();
        int[] counts = new int[26]; // 剩余字符数目
        boolean[] exsits = new boolean[26];
        for (char c : s.toCharArray()) {
            counts[c - 'a'] += 1;
        }
        for (char c : s.toCharArray()) {
            counts[c - 'a'] -= 1;
            if (!exsits[c - 'a']) {
                while (!stack.isEmpty() && stack.peek() > c && counts[stack.peek() - 'a'] > 0) {
                    char c1 = stack.removeFirst();
                    exsits[c1 - 'a'] = false;
                }
                stack.addFirst(c);
                exsits[c - 'a'] = true;
            }
        }
        StringBuilder res = new StringBuilder();
        while (!stack.isEmpty()) {
            res.append(stack.removeLast());
        }
        return res.toString();
    }
}
