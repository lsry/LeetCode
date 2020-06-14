package review;

public class R29 {
    public int[] spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0 ||matrix[0].length == 0) {
            return new int[]{};
        }
        int N = matrix.length, M = matrix[0].length;
        int top = 0, bottom = N;
        int left = 0, right = M;
        int[] res = new int[N * M];
        int index = 0;
        while (top < bottom && left < right && index < M * N) {
            // top
            for (int i = left;i < right && index < M * N;++i) {
                res[index] = matrix[top][i];
                ++index;
            }
            // right
            for (int j = top + 1;j < bottom && index < M * N;++j) {
                res[index] = matrix[j][right - 1];
                ++index;
            }
            // bottom
            for (int i = right - 2;i >= left && index < M * N;--i) {
                res[index] = matrix[bottom - 1][i];
                ++index;
            }
            // left
            for (int j = bottom - 2;j > top && index < M * N;--j) {
                res[index] = matrix[j][left];
                ++index;
            }
            ++top;
            ++left;
            --bottom;
            --right;
        }
        return res;
    }
}