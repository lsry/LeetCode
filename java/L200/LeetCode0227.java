package L200;

import java.util.Deque;
import java.util.LinkedList;

/**
 * S = S + A | S - A | A
 * A = A * N | A / N | N
 * N = digit | ( S )
 */
public class LeetCode0227 {
    private int N;
    Deque<Integer> nums;
    public int calculate(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        N = s.length();
        nums = new LinkedList<>();
        start(s, 0);
        return nums.getFirst();
    }

    private int ensure(String s, int i) {
        while (i < N && s.charAt(i) == ' ') {
            ++i;
        }
        return i;
    }

    private int start(String s, int i) {
        i = ensure(s, i);
        if (i >= N) {
            return i;
        }
        i = A(s, i);
        i = start1(s, i);
        return i;
    }

    private int start1(String s, int i) {
        i = ensure(s, i);
        if (i >= N) {
            return i;
        }
        char ch = s.charAt(i);
        if (ch == '+' || ch == '-') {
            i = A(s, i + 1);
            int b = nums.removeFirst();
            int a = nums.removeFirst();
            a = ch == '+' ? a + b : a - b;
            nums.addFirst(a);
            i = start1(s, i);
        }
        return i;
    }

    private int A(String s, int i) {
        i = ensure(s, i);
        if (i >= N) {
            return i;
        }
        i = getNum(s, i);
        i = A1(s, i);
        return i;
    }

    private int A1(String s, int i) {
        i = ensure(s, i);
        if (i >= N) {
            return i;
        }
        char ch = s.charAt(i);
        if (ch == '*' || ch == '/') {
            i = getNum(s, i + 1);
            int b = nums.removeFirst();
            int a = nums.removeFirst();
            a = ch == '*' ? a * b : a / b;
            nums.addFirst(a);
            i = A1(s, i);
        }
        return i;
    }

    private int getNum(String s, int i) {
        i = ensure(s, i);
        if (i >= N) {
            return i;
        }
        int a = 0;
        while (i < N && Character.isDigit(s.charAt(i))) {
            a = a * 10 + (s.charAt(i) - '0');
            ++i;
        }
        nums.addFirst(a);
        return i;
    }

    public static void main(String[] args) {
        LeetCode0227 code = new LeetCode0227();
        System.out.println(code.calculate("12*25+23-34"));
        System.out.println(code.calculate("3 + 5 / 3 * 2 - 4 * 3"));
        System.out.println(code.calculate("2 - 3 + 2"));
    }
}
