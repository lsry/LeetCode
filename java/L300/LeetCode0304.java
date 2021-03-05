package L300;

public class LeetCode0304 {}

class NumMatrix {
    private int[][] ma;
    public NumMatrix(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return;
        }
        this.ma = new int[matrix.length + 1][matrix[0].length + 1];
        for (int i = 0;i < matrix.length;++i) {
            for (int j = 0;j < matrix[0].length;++j) {
                this.ma[i + 1][j + 1] = this.ma[i][j + 1] + this.ma[i + 1][j] + matrix[i][j] - ma[i][j];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return ma[row2 + 1][col2 + 1] - ma[row1][col2 + 1] - ma[row2 + 1][col1] + ma[row1][col1];
    }
}