package L1400;

public class LeetCode1442 {
    public int countTriplets(int[] arr) {
        int N = arr.length;
        int[] pre = new int[N + 1];
        for (int i = 1;i <= N;++i) {
            pre[i] = arr[i - 1] ^ pre[i - 1];
        }
        int count = 0;
        /**
         * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
         * b = arr[j] ^ ... ^ arr[k]
         * a = b  
         * -> pre[j - 1] ^ pre[i - 1] = pre[k] ^ pre[j - 1]
         * -> pre[i - 1] = pre[k]
         */
        for (int i = 0;i < N;++i) {
            for (int k = i + 2;k <= N;++k) {
                if (pre[i] == pre[k]) {
                    count += k - i - 1;
                }
            }
        }
        return count;
    }
}
