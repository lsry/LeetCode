package L900;

public class LeetCode0941 {
    public boolean validMountainArray(int[] A) {
        if (A.length < 3 || A[0] >= A[1] || A[A.length - 1] >= A[A.length - 2]) {
            return false;
        }
        int i = 1;
        for (;i < A.length - 1;++i) {
            if (A[i] == A[i - 1]) {
                return false;
            }
            if (A[i] < A[i - 1]) {
                break;
            }
        }
        for (;i < A.length - 1;++i) {
            if (A[i] <= A[i + 1]) {
                return false;
            }
        }
        return true;
    }
}
