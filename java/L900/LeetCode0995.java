package L900;

public class LeetCode0995 {
    public int minKBitFlips(int[] A, int K) {
        final int N = A.length;
        int[] diff = new int[N + 1];
        int revCnt = 0, ans = 0;
        for (int i = 0;i < N;++i) {
            revCnt += diff[i];
            if ((A[i] + revCnt) % 2 == 0) {
                if (i + K > N) {
                    return -1;
                }
                ++ans;
                ++revCnt;
                --diff[i + K];
            }
        }
        return ans;
    }
}
