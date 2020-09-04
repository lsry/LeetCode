package L300;

public class LeetCode0392 {
    /**
     * 双指针，判断 t 中是否存在一种 s
     */
    public boolean isSubsequenceDPoint(String s, String t) {
        int sl = 0, tl = 0;
        while(sl < s.length() && tl < t.length()){
            if (t.charAt(tl) == s.charAt(sl)){
                sl++;
            }
            tl++;
        }
        return sl >= s.length();
    }

    /**
     * dp[i][j] = t 中从 i 开始 j 的位置
     */
    public boolean isSubsequence(String s, String t) {
        final int TN = t.length();
        int[][] dp = new int[TN + 1][26];
        for (int i = TN;i >= 0;--i) {
            for (int j = 0;j < 26;++j) {
                if (i == TN) {
                    dp[i][j] = TN;
                } else {
                    if (t.charAt(i) == 'a' + j) {
                        dp[i][j] = i;
                    } else {
                        dp[i][j] = dp[i + 1][j];
                    }
                }
            }
        }
        int tl = 0;
        for (char sc : s.toCharArray()) {
            if (dp[tl][sc - 'a'] == TN) { // 判断在指定位置是否能找到字符
                return false;
            }
            tl = dp[tl][sc - 'a'] + 1;
        }
        return true;
    }
}