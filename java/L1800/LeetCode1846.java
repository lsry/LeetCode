package L1800;

import java.util.Arrays;

public class LeetCode1846 {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        Arrays.sort(arr);
        arr[0] = 1;
        for (int i = 1;i < arr.length;++i) {
            if (Math.abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr[arr.length - 1];
    }
}