package L1700;

import java.util.Arrays;

public class LeetCode1738 {
    public int kthLargestValue(int[][] matrix, int k) {
        final int M = matrix.length, N = matrix[0].length;
        int[][] pre = new int[M + 1][N + 1];
        int[] totals = new int[M * N];
        int index = 0;
        for (int i = 1;i <= M;++i) {
            for (int j = 1;j <= N;++j) {
                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                totals[index] = pre[i][j];
                ++index;
            }
        }
        // return nth_element(totals, 0, M * N - 1, k - 1);  // TLE
        Arrays.sort(totals);
        return totals[M * N - k - 1];
    }

    private int nth_element(int[] arr, int b, int e, int k) {
        if (b >= e) {
            return arr[e];
        }
        int q = partition(arr, b, e);
        if (q == k) {
            return arr[q];
        } else if (q > k) {
            return nth_element(arr, b, q - 1, k);
        } else {
            return nth_element(arr, q + 1, e, k);
        }
    }

    private int partition(int[] arr, int b, int e) {
        int i = b - 1;
        for (int j = b;j < e;++j) {
            if (arr[j] >= arr[e]) {
               ++i;
               int t = arr[j];
               arr[j] = arr[i];
               arr[i] = t;
            } 
        }
        int t = arr[e];
        arr[e] = arr[i + 1];
        arr[i + 1] = t;
        return i + 1;
    }
}
