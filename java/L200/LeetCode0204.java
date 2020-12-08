package L200;

public class LeetCode0204 {
    /**
     * 
     */
    public int countPrimes(int n) {
        int ans = 0;
        boolean[] dp = new boolean[n + 1];
        for (int i = 2;i <= n;++i) {
            if (dp[i] == false && isPrime(i)) {
                ++ans;
                for (int j = 1;j * i  <= n;++j) {
                    dp[j * i] = true;
                }
            }
        }
        return ans;
    }

    private boolean isPrime(int n) {
        for (int i = 2;i * i <= n;++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
