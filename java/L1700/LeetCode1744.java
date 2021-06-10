package L1700;

public class LeetCode1744 {
    /**
     * 用 long 防止数据溢出
     */
    public boolean[] canEat(int[] candiesCount, int[][] queries) {
        long[] pre = new long[candiesCount.length + 1];
        for (int i = 1;i <= candiesCount.length;++i) {
            pre[i] = pre[i - 1] + candiesCount[i - 1];
        }
        boolean[] answers = new boolean[queries.length];
        for (int i = 0;i < queries.length;++i) {
            long latesday = pre[queries[i][0] + 1];
            long earliestday = pre[queries[i][0]] / queries[i][2] + 1;
            long d = queries[i][1] + 1;
            answers[i] = d >= earliestday && d <= latesday;
        }
        return answers;
    }
}
