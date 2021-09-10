package L1600;

public class LeetCode1646 {
    public int getMaximumGenerated(int n) {
        if (n == 0) {
            return 0;
        }
        int[] arr = new int[n + 1];
        arr[1] = 1;
        int max = 1;
        for (int i = 2;i <= n;++i) {
            int x = i / 2;
            if (i % 2 == 0) {
                arr[i] = arr[x];
            } else {
                arr[i] = arr[x] + arr[x + 1];
            }
            max = Math.max(max, arr[i]);
        }
        return max;
    }
}