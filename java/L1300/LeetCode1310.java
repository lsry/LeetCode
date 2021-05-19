package L1300;

public class LeetCode1310 {
    public int[] xorQueries(int[] arr, int[][] queries) {
        final int N = arr.length;
        int[] pre = new int[N + 1];
        for (int i = 1;i <= N;++i) {
            pre[i] = pre[i - 1] ^ arr[i - 1];
        }
        int[] res = new int[queries.length];
        for (int i = 0;i < queries.length;++i) {
            res[i] = pre[queries[i][1] + 1] ^ pre[queries[i][0]];
        }
        return res;
    }
}
