package L2000;

public class LeetCode2022 {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if (original.length != n * m) {
            return new int[][]{};
        }
        int[][] arr = new int[m][n];
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                arr[i][j] = original[i * n + j];
            }
        }
        return arr;
    }
}
