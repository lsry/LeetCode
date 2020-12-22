package L000;

public class LeetCode0048 {
    /**
     * 把矩阵看成一个个圈，依次从外到里，旋转元素
     * @param matrix
     */
    public void rotate(int[][] matrix) {
        final int N = matrix.length;
        for (int i = 0;i < N / 2;++i) {
            for (int j = i;j < N - i - 1;++j) {
                int t1 = matrix[j][N - i - 1];
                matrix[j][N - i - 1] = matrix[i][j];
                int t2 = matrix[N - i - 1][(N - i - 1) - (j - i)];
                matrix[N - i - 1][(N - i - 1) - (j - i)] = t1;
                t1 = matrix[(N - i - 1) - (j - i)][i];
                matrix[(N - i - 1) - (j - i)][i] = t2;
                matrix[i][j] = t1;
            }
        }
    }
}
