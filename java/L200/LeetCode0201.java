package L200;

public class LeetCode0201 {
    /**
     * 寻找两个数的公共前缀，然后将末尾补零
     */
    public int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while (m < n) {
            m = m >> 1;
            n = n >> 1;
            ++shift;
        }
        return m << shift;
    }
}