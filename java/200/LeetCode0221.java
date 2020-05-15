public class LeetCode0221 {
    public int maximalSquare(char[][] matrix) {
        int maxArea = 0;        
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        int R = matrix.length, C = matrix[0].length;
        for (int i = 0;i < R;++i) {
            for (int j = 0;j < C;++j) {
                if (matrix[i][j] == '1') {
                    int curArea = 1;
                    boolean flag = true;
                    int a = 1;
                    // 每次为当前正方形增加一行一列
                    for (;flag && i + a < R && j + a < C;++a) {                       
                        for (int q = 0;q <= a;++q) {
                            if (matrix[i + a][j + q] == '0' || matrix[i + q][j + a] == '0') {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            curArea = (a + 1) * (a + 1);
                        }
                    }
                    maxArea = maxArea > curArea ? maxArea : curArea;
                }
            }
        }
        return maxArea;
    }
}