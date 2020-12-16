package L000;

public class LeetCode0062 {
    public int uniquePaths(int m, int n) {
        int[] path = new int[m];
        for (int i = 1;i < m;++i) {
            path[i] = 1;
        }
        if (n > 1) {
            path[0] = 1;
        }
        for (int i = 1;i < n;++i) {
            for (int j = 1;j < m;++j) {
                path[j] += path[j - 1];
            }
        }
        return path[m - 1];
    }
}
