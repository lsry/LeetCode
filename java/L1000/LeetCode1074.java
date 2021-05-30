package L1000;

import java.util.HashMap;

public class LeetCode1074 {
    public int numSubmatrixSumTarget(int[][] matrix, int target) {
        final int M = matrix.length, N = matrix[0].length;
        int ans = 0;
        for (int i = 0;i < M;++i) {
            int[] colsum = new int[N];
            for (int j = i;j < M;++j) {
                for (int k = 0;k < N;++k) {
                    colsum[k] += matrix[j][k];
                }
                ans += findSubArray(colsum, target);
            }
        }
        return ans;
    }

    private int findSubArray(int[] arr, int target) {
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0, 1);
        int pre = 0;
        int ans = 0;
        for (int i = 0;i < arr.length;++i) {
            pre += arr[i];
            int diff = pre - target;
            if (map.containsKey(diff)) {
                ans += map.get(diff);
            }
            map.put(pre, map.getOrDefault(pre, 0) + 1);
        }
        return ans;
    }
}
