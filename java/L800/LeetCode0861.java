package L800;

public class LeetCode0861 {
    public int matrixScore(int[][] A) {
        final int M = A.length, N = A[0].length;
        int ans = M * (1 << (N - 1));
        for (int j = 1;j < N;++j) {
            int ones = 0;
            for (int i = 0;i < M;++i) {
                if (A[i][0] == 1) {
                    ones += A[i][j];
                } else {
                    ones += (1 - A[i][j]);
                }
            }
            ones = Math.max(ones, M - ones);
            ans += ones * (1 << (N - 1 - j));
        }
        return ans;
    }
}
