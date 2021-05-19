package L1700;

public class LeetCode1734 {
    public int[] decode(int[] encoded) {
        final int N = encoded.length + 1;
        int x = 1;
        for (int i = 2;i <= N;++i) {
            x = x ^ i;
        }
        for (int i = 1;i < encoded.length;i += 2) {
            x = x ^ encoded[i];
        }
        int[] res = new int[N];
        res[0] = x;
        for (int i = 1;i < N;++i) {
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        return res;
    }
}
