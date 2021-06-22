package L000;

public class LeetCode0065 {
    public boolean isNumber(String s) {
        int index = 0;
        int N = s.length();
        char[] chs = s.toCharArray();
        if (index < N && (chs[index] == '+' || chs[index] == '-')) {
            ++index;
        }
        boolean hasInt = false; // 小数点前有数字
        if (index < N && Character.isDigit(chs[index])) {
            hasInt = true;
            while (index < N && Character.isDigit(chs[index])) {
                ++index;
            }
        }
        boolean hasRat = false;
        if (index < N && chs[index] == '.') {
            ++index;
            if (!hasInt && index == N) {
                return false;
            }
            if (index < N && Character.isDigit(chs[index])) {
                hasRat = true;
                while (index < N && Character.isDigit(chs[index])) {
                    ++index;
                }
            }
            hasRat = hasRat || hasInt; // 形成小数
        }
        if (index < N && (chs[index] == 'e' || chs[index] == 'E')) {
            ++index;
            boolean hasEnum = false;
            if (index < N && (chs[index] == '+' || chs[index] == '-')) {
                ++index;
            }
            if (index < N && Character.isDigit(chs[index])) {
                ++index;
                hasEnum = true; // E 后面有数字
                while (index < N && Character.isDigit(chs[index])) {
                    ++index;
                }
            }
            if (!(hasInt || hasRat) || !hasEnum) {
                return false;
            }
        }
        return index == N;
    }

    public static void main(String[] args) {
        LeetCode0065 code = new LeetCode0065();
        String[] valid = new String[]{"2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"};
        System.out.println("valid num: ");
        for (int i = 0;i < valid.length;++i) {
            System.out.println(valid[i] + ": " + code.isNumber(valid[i]));
        }

        String[] invalid = new String[]{"abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53",".",".e1"};
        System.out.println("\ninvalid num: ");
        for (int i = 0;i < invalid.length;++i) {
            System.out.println(invalid[i] + ": " + code.isNumber(invalid[i]));
        }
    }
}