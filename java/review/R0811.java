package review;

public class R0811 {
    /**
     * 用前 i 种硬币组成面值为n 的个数
     * 前i种硬币需要从小到大排序
     * f(i,n) = f(i,n - k * ci) (n - k * ci >= 0)
     */
    public int waysToChange(int n) {
        int MOD = 1000000007;
        int[] indics = new int[]{1,5,10,25};
        int[] counts = new int[n + 1];
        counts[0] = 1;
        for (int m : indics) {
            for (int i = m;i <= n;++i) {
                counts[i] = (counts[i - m] + counts[i]) % MOD;
            }
        }
        return counts[n];
    }
}