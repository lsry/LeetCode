package L1100;

import java.util.Deque;
import java.util.LinkedList;

public class LeetCode1111 {
    public int[] maxDepthAfterSplit(String seq) {
        if (seq == null || seq.length() == 0) {
            return new int[]{};
        }
        int[] res = new int[seq.length()];
        int flag = 1;
        Deque<Integer> stack = new LinkedList<>();
        char[] chs = seq.toCharArray();
        for (int i = 0;i < chs.length;++i) {
            if (chs[i] == '(') {
                flag = (flag + 1) % 2;
                res[i] = flag;
                stack.addFirst(flag);
            } else {
                int t = stack.removeFirst();
                res[i] = t;
                flag = stack.isEmpty() ? 0 : stack.getFirst();
            }
        }
        return res;
    }
}