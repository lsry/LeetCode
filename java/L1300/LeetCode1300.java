package L1300;

import java.util.Arrays;

public class LeetCode1300 {
    public int findBestValue(int[] arr, int target) {
        Arrays.sort(arr);
        int[] prex = new int[arr.length + 1];
        for (int i = 1;i <= arr.length;++i) {
            prex[i] = arr[i - 1] + prex[i - 1];
        }
        int ans = 0, diff = target;
        for (int value = 1;value <= arr[arr.length - 1];++value) {
            int index = Arrays.binarySearch(arr, value);
            if (index < 0) {
                index = -index - 1;
            }
            int cur = prex[index] + (arr.length - index) * value;
            if (Math.abs(cur - target) < diff) {
                ans = value;
                diff = Math.abs(cur - target);
            }
        }
        return ans;
    }
}