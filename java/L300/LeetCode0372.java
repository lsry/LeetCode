package L300;

public class LeetCode0372 {
    private static final int MOD = 1337;
    public int superPow(int a, int[] b) {
        int a0 = a % MOD;
        if (b == null || b.length == 0) {
            return a0;
        }
        int[] pow = new int[11];
        pow[0] = 1;
        for (int i = 1;i < pow.length;++i) {
            pow[i] = (pow[i - 1] * a0) % MOD;
        }
        int res = 1;
        for (int i = 0;i < b.length;++i) {
            int t = res;
            for (int j = 1;j < 10;++j) {
                res = (res * t) % MOD;
            }
            res = (res * pow[b[i]]) % MOD;
        }
        return res;
    }
}
