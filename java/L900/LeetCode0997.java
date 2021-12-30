package L900;

public class LeetCode0997 {
    public int findJudge(int n, int[][] trust) {
        boolean[] flags = new boolean[n + 1];
        int[] counts = new int[n + 1];
        for (int[] t : trust) {
            flags[t[0]] = true;
            counts[t[1]]++;
        }
        for (int i = 1;i <= n;++i) {
            if (!flags[i] && counts[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
}