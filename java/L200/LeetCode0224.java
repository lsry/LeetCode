package L200;

import java.util.Deque;
import java.util.LinkedList;

/**
 * S = (S) | S + S | S - S | +S | -S | N   
 * 消除左递归：
 * S = (S)S' | +SS' | -SS' | NS'
 * S' = +SS' | -SS' | null
 */
public class LeetCode0224 {
    int N;
    int res;
    boolean sign = true;
    Deque<Integer> nums = new LinkedList<>();
    Deque<Boolean> ops = new LinkedList<>();
    public int calculate(String s) {
        N = s.length();
        res = 0;
        start(s, 0);
        return res;
    }

    private int start(String s, int i) {
        while (i < N && s.charAt(i) == ' ') {
            ++i;
        }
        if (i >= N) {
            return N;
        }
        if (s.charAt(i) == '(') {
            i = brack(s, i);
        } else if (Character.isDigit(s.charAt(i))){
            i = getNums(s, i);
        } else {
            i = getOp(s, i);
            i = start(s, i);
        }
        i = start1(s, i);
        return i;
    }

    private int start1(String s, int i) {
        while (i < N && s.charAt(i) == ' ') {
            ++i;
        }
        if (i >= N) {
            return N;
        }
        if (s.charAt(i) == '+' || s.charAt(i) == '-') {
            i = getOp(s, i);
            i = start(s, i);
            i = start1(s, i);
        }
        return i;
    }

    private int getNums(String s, int i) {
        while (i < N && s.charAt(i) == ' ') {
            ++i;
        }
        if (i >= N) {
            return N;
        }
        int a = 0;
        while (i < N && Character.isDigit(s.charAt(i))) {
            a = a * 10 + (s.charAt(i) - '0');
            ++i;
        }
        if (sign) {
            res += a;
        } else {
            res -= a;
        }
        return i;
    }

    private int brack(String s, int i) {
        ++i;
        nums.addFirst(res);
        ops.addFirst(sign);
        res = 0;
        sign = true;
        i = start(s, i);
        while (i < N && s.charAt(i) != ')') {
            ++i;
        }
        int last = nums.removeFirst();
        boolean lastop = ops.removeFirst();
        res = lastop ? last + res : last - res;
        sign = true;
        return i + 1;
    }

    private int getOp(String s, int i) {
        while (i < N && s.charAt(i) == ' ') {
            ++i;
        }
        if (i >= N) {
            return N;
        }
        char op = s.charAt(i);
        if (op == '+') {
            sign = true;
        } else if (op == '-') {
            sign = false;
        }
        return i + 1;
    }

    public static void main(String[] args) {
        LeetCode0224 code = new LeetCode0224();
        System.out.println("1: " + (11 == code.calculate("(7) - (0) + (4)")));
        System.out.println("2: " + (-12 == code.calculate("- (3 + (4 + 5))")));
    }
}
