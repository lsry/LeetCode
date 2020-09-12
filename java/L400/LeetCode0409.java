package L400;

public class LeetCode0409 {
    public int longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        int[][] alpha = new int[2][26];
        for (char c : s.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                alpha[0][c - 'a']++;
            } else {
                alpha[1][c - 'A']++;
            }
        }
        int length = 0, one = 0;
        for (int i = 0;i < 2;++i) {
            for (int j = 0;j < 26;++j) {
                if (alpha[i][j] % 2 == 0) {
                    length += alpha[i][j];
                } else {
                    length += alpha[i][j] - 1;
                    one++;
                }
            }
        }
        if (one > 0) {
            length++;
        }
        return length;
    }
}