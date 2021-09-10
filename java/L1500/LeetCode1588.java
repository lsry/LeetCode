package L1500;

public class LeetCode1588 {
    public int sumOddLengthSubarrays(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        int N = arr.length;
        int[] pre = new int[N + 1];
        for (int i = 1;i <= N;++i) {
            pre[i] = pre[i - 1] + arr[i - 1];
        }
        int ans = 0;
        for (int i = 1;i <= N;++i) {
            ans += arr[i - 1];
            for (int j = 2;i + j <= N;j += 2) {
                ans += pre[i + j] - pre[i - 1];
            }
        }
        return ans;
    }
}