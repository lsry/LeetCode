package L000;

public class LeetCode0074 {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) {
            return false;
        }
        final int M = matrix.length, N = matrix[0].length;
        int i = 0, j = M - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (matrix[m][0] == target) {
                return true;
            } else if (j - i == 1) {
                if (matrix[j][0] <= target) {
                    i = j;
                }
                break;
            } else if (matrix[m][0] > target) {
                j = m - 1;
            } else {
                i = m;
            }
        }
        int t = i;
        i = 0; 
        j = N - 1;
        while (i <= j) {
            int m = (i + j) / 2;
            if (matrix[t][m] == target) {
                return true;
            } else if (matrix[t][m] > target) {
                j = m - 1;
            } else {
                i = m + 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        LeetCode0074 code = new LeetCode0074();
        code.searchMatrix(new int[][]{{1,3,5,7},{10,11,16,20},{23,30,34,60}}, 11);
    }
}
