package L200;

import java.util.Arrays;

public class LeetCode0220 {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums == null || nums.length < 2) {
            return false;
        }
        final int N = nums.length;
        int[][] arr = new int[N][2];
        for (int i = 0;i < N;++i) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }
        Arrays.sort(arr, (a, b) -> {
            return Integer.compare(a[0], b[0]);
        });
        for (int i = 0;i < N;++i) {
            for (int j = i + 1;j < N && (long)arr[j][0] - (long)arr[i][0] <= (long)t;++j) {
                int indexdiff = Math.abs(arr[j][1] - arr[i][1]);
                if (indexdiff <= k) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        LeetCode0220 code = new LeetCode0220();
        code.containsNearbyAlmostDuplicate(new int[]{1,5,9,1,5,9}, 2, 3);
    }
}
