public class LeetCode0044 {
    public boolean isMatch(String s, String p) {
        int SN = s.length(), PN = p.length();
        boolean[][] dp = new boolean[SN + 1][PN + 1];
        dp[0][0] = true;
        for (int i = 1;i <= PN;++i) {  // 当 p[0,...,i - 1] 均为 *，dp[0][i] = true
            if (p.charAt(i - 1) == '*') {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        for (int i = 1;i <= SN;++i) {
            for (int j = 1;j <= PN;++j) {
                char pc = p.charAt(j - 1);
                if (pc == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pc == '*') {
                    if (j == 1) {
                        dp[i][j] = true;
                    } else { // 选择使用或者不使用 * 
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    }
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s.charAt(i - 1) == pc);
                }
            }
        }
        return dp[SN][PN];
    }

    public static void main(String[] args) {
        LeetCode0044 code = new LeetCode0044();
        System.out.println("1: " + (code.isMatch("a", "*") == true));
        System.out.println("2: " + (code.isMatch("aa", "a") == false));
        System.out.println("3: " + (code.isMatch("ab", "a?") == true));
        System.out.println("4: " + (code.isMatch("ab", "c?") == false));
        System.out.println("5: " + (code.isMatch("aa", "*") == true));
        System.out.println("6: " + (code.isMatch("acdcb", "a*c?b") == false));
        System.out.println("7: " + (code.isMatch("adceb", "*a*b") == true));
        System.out.println("8: " + (code.isMatch("", "*") == true));
        System.out.println("9: " + (code.isMatch("ho", "**ho") == true));
    }
}