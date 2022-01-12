package L300;

public class LeetCode0306 {
    private int N;
    public boolean isAdditiveNumber(String num) {
        N = num.length();
        return trace(num, 0L, 0L, 0, 1);
    }

    private boolean trace(String num, long v1, long v2, int index, int count) {
        if (index >= N) {
            return count > 3;
        }
        if (num.charAt(index) == '0') {
            if (count > 2 && v1 + v2 != 0L) {
                return false;
            }
            return trace(num, v2, 0L, index + 1, count + 1);
        }
        for (int i = index + 1;i <= N;++i) {
            long v3 = Long.parseLong(num.substring(index, i));
            if ((count < 3 || v1 + v2 == v3) && trace(num, v2, v3, i, count + 1)) {
                return true;
            } 
        }
        return false;
    }

    public static void main(String[] args) {
        LeetCode0306 code = new LeetCode0306();
        code.isAdditiveNumber("101");
    }
}
