package L700;

public class LeetCode0765 {
    public int minSwapsCouples(int[] row) {
        final int n = row.length;
        int[] map = new int[n];
        for (int i = 0;i < n;++i) {
            map[row[i]] = i;
        }
        int change = 0;
        for (int i = 0;i < n;i += 2) {
            if (row[i] % 2 == 0 && row[i + 1] != row[i] + 1) {
                ++change;
                int t = row[i + 1];
                int p = map[row[i] + 1];
                row[p] = t;
                map[t] = p;
                row[i + 1] = row[i] + 1;
            } else if (row[i] % 2 != 0 && row[i + 1] != row[i] - 1) {
                ++change;
                int t = row[i + 1];
                int p = map[row[i] - 1];
                row[p] = t;
                map[t] = p;
                row[i + 1] = row[i] - 1;
            }
        }
        return change;
    }
}
