package L1000;

public class LeetCode1004 {
    public int longestOnes(int[] A, int K) {
        int ones = 0;
        int k = K;
        for (int i = 0,j = 0;j < A.length;) {
            while (j < A.length) {
                if (A[j] == 0) {
                    if (k == 0) {
                        break;
                    }
                    --k;
                }
                ++j;
            }
            ones = Math.max(ones, j - i);
            while (i < A.length && A[i] == 1) {
                ++i;
            }
            i += 1;
            if (j < i) {
                j = i;
            }
            if (k < K) {
                ++k;
            }
        }
        return ones;
    }
}
