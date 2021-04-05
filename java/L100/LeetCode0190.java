package L100;

public class LeetCode0190 {
    public int reverseBits(int n) {
        int r = 0;
        int i = 0;
        while (n != 0) {
            if ((n & 1) == 1) {
                r = (r << 1) + 1;
            } else {
                r = r << 1;
            }
            ++i;
            n = (n >>> 1);
        }
        while (i < 32) {
            ++i;
            r = r << 1;
        }
        return r;
    }
}
