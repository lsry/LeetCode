package L200;

public class LeetCode0231 {
    /**
     * 如果是 2 的幂，则二进制只有一个 1，其余为 0；
     */
    public boolean isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
}
