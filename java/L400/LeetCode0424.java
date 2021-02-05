package L400;

public class LeetCode0424 {
    public int characterReplacement(String s, int k) {
        int max = 0;
        final int N = s.length();
        for (int i = 0;i < N;) {
            int j = i, tk = k;
            while (j < N && tk >= 0) {
                if (s.charAt(j) == s.charAt(i)) {
                    ++j;
                } else if (tk > 0) {
                    --tk;
                    ++j;
                } else {
                    break;
                }
            }
            int p = i - 1;
            if (tk > 0) {
                while (p >= 0 && tk >= 0) {
                    if (s.charAt(p) == s.charAt(i)) {
                        --p;
                    } else if (tk > 0) {
                        --tk;
                        --p;
                    } else {
                        break;
                    }
                }
            }
            max = Math.max(max, j - p - 1);
            p = i;
            while (i < N && s.charAt(i) == s.charAt(p)) {
                ++i;
            }
        }
        return max;
    }
}
