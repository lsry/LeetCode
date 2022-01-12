package L000;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode0071 {
    public String simplifyPath(String path) {
        Deque<String> stack = new LinkedList<>();
        final int N = path.length();
        for (int i = 0;i < N;) {
            while (i < N && path.charAt(i) == '/') {
                ++i;
            }
            if (i >= N) {
                break;
            }
            int j = i;
            while (i < N && path.charAt(i) != '/') {
                ++i;
            }
            if (i - j == 1 && path.charAt(j) == '.') {
                continue;
            } else if (i - j == 2 && path.charAt(j) == '.' && path.charAt(j + 1) == '.') {
                if (!stack.isEmpty()) {
                    stack.removeFirst();
                }
            } else {
                stack.addFirst(path.substring(j, i));
            }
        }
        if (stack.isEmpty()) {
            return "/";
        }
        StringBuilder sBuilder = new StringBuilder();
        while (!stack.isEmpty()) {
            sBuilder.append('/').append(stack.removeLast());
        }
        return sBuilder.toString();
    }
}