public class R0107 {
    // 先绕（0，0）顺时针旋转 90，然后向上平移 N-1 个单位
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        for (int x = 0;x < N / 2;++x) {
            for (int y = x;y < N - 1 - x;++y) {
                int nx = x, ny = y;
                int value = matrix[x][y];
                for (int i = 0;i < 4;++i) {
                    int nx2 = ny;
                    int ny2 = -nx + N - 1;
                    int temp = matrix[nx2][ny2];
                    matrix[nx2][ny2] = value;
                    value = temp;
                    nx = nx2;
                    ny = ny2;
                }
            }
        }
    }
}