package L000;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0054 {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<>(matrix.length * matrix[0].length);
        int l = 0, r = matrix[0].length - 1;
        int t = 0, b = matrix.length - 1;
        while (l <= r && t <= b) {
            for (int i = l;i <= r;++i) {
                res.add(matrix[t][i]);
            }
            for (int i = t + 1;i <= b;++i) {
                res.add(matrix[i][r]);
            }
            // 若同列或同行，会重复
            for (int i = r - 1;b > t && i >= l;--i) {
                res.add(matrix[b][i]);
            }
            for (int i = b - 1;i > t && l < r;--i) {
                res.add(matrix[i][l]);
            }
            ++l;
            --r;
            ++t;
            --b;
        }
        return res;
    }
}
