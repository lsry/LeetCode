package L300;

import java.util.TreeSet;

public class LeetCode0363 {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        final int M = matrix.length, N = matrix[0].length;
        int[][] presum = new int[M + 1][N + 1];
        for (int i = 1;i <= M;++i) {
            for (int j = 1;j <= N;++j) {
                presum[i][j] = matrix[i - 1][j - 1] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
            }
        }
        int ans = Integer.MIN_VALUE;
        for (int top = 1;top <= M;++top) {
            for (int bot = top;bot <= M;++bot) {
                TreeSet<Integer> set = new TreeSet<>();
                set.add(0);
                for (int right = 1;right <= N;++right) {
                    int rv = presum[bot][right] - presum[top - 1][right] - presum[bot - 1][0] + presum[top - 1][0];
                    // 目标 s[r] - s[l - 1] 最大，可使 s[r] 最大，或者 s[l - 1] 最小
                    // 此外 s[r] - s[l - 1] <= k
                    // 固定 r，s[l - 1] >= s[r] - k, 于是为了让 s[r] - s[l - 1] 最大，则找大于等于 s[r] - k 的最小值
                    // 固定 l - 1, s[r] <= s[l - 1] + k, 找小于等于 s[l - 1] + k 的最小值
                    Integer lv = set.ceiling(rv - k);
                    if (lv != null) {
                        ans = Math.max(ans, rv - lv);
                    }
                    set.add(rv);
                }
            }
        }
        return ans;
    }
}
