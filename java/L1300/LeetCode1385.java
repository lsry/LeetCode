package L1300;

import java.util.Arrays;

public class LeetCode1385 {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        Arrays.sort(arr2);
        int ans = 0;
        for (int n : arr1) {
            int l = 0, r = arr2.length - 1;
            boolean flag = true;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (Math.abs(n - arr2[mid]) <= d) {
                    flag = false;
                    break;
                }
                if (arr2[mid] <= n) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (flag) {
                ans++;
            }
        }
        return ans;
    }
}