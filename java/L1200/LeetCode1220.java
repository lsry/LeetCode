package L1200;

public class LeetCode1220 {
    private static final long MOD = 1_000_000_007;
    /**
     * 以当前位置为末尾，枚举每个字母前面可能的字母，然后计算数目和
     */
    public int countVowelPermutation(int n) {
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 2;k <= n;++k) {
            long aa = (e + i + u) % MOD;
            long ee = (a + i) % MOD;
            long ii = (e + o) % MOD;
            long oo = i % MOD;
            long uu = (o + i) % MOD;
            a = aa;
            e = ee;
            i = ii;
            o = oo;
            u = uu;
        }
        return (int)((a + e + i + u + o) % MOD);
    }
}
