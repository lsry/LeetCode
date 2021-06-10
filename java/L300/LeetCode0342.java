package L300;

public class LeetCode0342 {
    private static final int odd = 0b01010101010101010101010101010101;
    public boolean isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & odd) != 0;
    }
}
