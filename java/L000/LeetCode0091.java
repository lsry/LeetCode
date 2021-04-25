package L000;

public class LeetCode0091 {
    /**
     * Time Limit Exceed
     * "111111111111111111111111111111111111111111111"
     */
    public int numDecodingsDfs(String s) {
        return path(s, 0);
    }

    private int path(String s, int index) {
        final int N = s.length();
        if (index >= N) {
            return 1;
        }
        if (s.charAt(index) == '0') {
            return 0;
        }
        int count = 0;
        for (int i = index + 1;i <= N;++i) {
            int v = Integer.valueOf(s.substring(index, i));
            if (v > 0 && v <= 26) {
                count += path(s, i);
            }
            if (v > 26) {
                break;
            }
        }
        return count;
    }

    public int numDecodings(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        final int N = s.length();
        int[] dp = new int[N + 1];
        dp[0] = 1;
        if (s.charAt(0) != '0') {
            dp[1] = 1;
        } else {
            return 0;
        }
        for (int i = 2;i <= N;++i) {
            int v = Integer.parseInt(s.substring(i - 2, i));
            if (s.charAt(i - 1) == '0') {
                if (s.charAt(i - 2) != '0' && v > 0 && v < 27) {
                    dp[i] = dp[i - 2];
                }
            } else {
                dp[i] = dp[i - 1];
                if (s.charAt(i - 2) != '0' && v > 0 && v < 27) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[N];
    }
}
