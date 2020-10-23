public class LeetCode0977 {
    public int[] sortedSquares(int[] A) {
        int index = 0;
        for (int i = 0;i < A.length;++i) {
            if (Math.abs(A[i]) < Math.abs(A[index])) {
                index = i;
            }
        }
        int[] res = new int[A.length];
        res[0] = A[index] * A[index];
        int p = 1;
        int i = index - 1, j = index + 1;
        while (i >= 0 || j < A.length) {
            if (i < 0) {
                res[p] = A[j] * A[j];
                ++p;
                ++j;
            } else if (j >= A.length) {
                res[p] = A[i] * A[i];
                ++p;
                --i;
            } else {
                if (Math.abs(A[i]) < Math.abs(A[j])) {
                    res[p] = A[i] * A[i];
                    ++p;
                    --i;
                } else {
                    res[p] = A[j] * A[j];
                    ++p;
                    ++j;
                }
            }
        }
        return res;
    }
}
