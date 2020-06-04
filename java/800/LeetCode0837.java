public class LeetCode0837 {
    private double[][] dp;
    public double new21GameMLE(int N, int K, int W) {
        dp = new double[N + 1][K + 1];
        return help(N, K, W);
    }

    private double help(int N, int K, int W) {
        if (K <= 0) {
            return 1.0;
        } else if (N <= 0) {
            return 0.0;
        } else if (dp[N][K] - 0.0 >= 1e-5) {
            return dp[N][K];
        }
        int min = Math.min(N, W);
        for (int i = 1;i <= min;++i) {
            dp[N][K] += 1.0/W * help(N - i, K - i, W);
        }
        return dp[N][K];
    }

    public double new21Game(int N, int K, int W) {
        if (K <= 0) {
            return 1.0;
        }
        double[] arr = new double[K + W];
        for (int i = K;i <= N && i < K + W;++i) {
            arr[i] = 1.0;
        }
        arr[K - 1] = Math.min(N - K + 1, W) * 1.0 / W;
        for (int i = K - 2;i >= 0;--i) {
            arr[i] = arr[i + 1] - (arr[i + W + 1] - arr[i + 1]) / W;
        }
        return arr[0];
    }
}