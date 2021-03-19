package L000;

public class LeetCode0059 {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        int l = 0, r = n - 1;
        int t = 0, b = n - 1;
        int v = 1;
        while (l <= r && t <= b) {
            for (int i = l;i <= r;++i) {
                res[t][i] = v;
                ++v;
            }
            for (int i = t + 1;i <= b;++i) {
                res[i][r] = v;
                ++v;
            }
            if (l < r && t < b) {
                for (int i = r - 1;i >= l;--i) {
                    res[b][i] = v;
                    ++v;
                }
                for (int i = b - 1;i > t;--i) {
                    res[i][l] = v;
                    ++v;
                }
            }
            ++l;
            --r;
            ++t;
            --b;
        }
        return res;
    }
}
