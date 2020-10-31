package L800;

public class LeetCode0845 {
    public int longestMountain(int[] A) {
        if (A == null || A.length < 3) {
            return 0;
        }
        int res = 0;
        for (int i = 1;i < A.length - 1;++i) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                int li = leftIndex(A, i);
                int ri = rightIndex(A, i);
                res = Math.max(res, ri - li + 1);
                i = ri + 1;
            }
        }
        return res;
    }

    private int leftIndex(int[] A, int index) {
        int i = index -1;
        for (;i >= 0;--i) {
            if (A[i] >= A[i + 1]) {
                break;
            }
        }
        return i + 1;
    }

    private int rightIndex(int[] A, int index) {
        int i = index + 1;
        for (;i < A.length;++i) {
            if (A[i] >= A[i - 1]) {
                break;
            }
        }
        return i - 1;
    }
}
