package L500;

public class LeetCode0551 {
    public boolean checkRecord(String s) {
        int A = 0, L = 0;
        for (char c : s.toCharArray()) {
            if (c == 'A') {
                ++A;
                L = 0;
            } else if (c == 'L') {
                ++L;
                if (L >= 3) {
                    return false;
                }
            } else {
                L = 0;
            }
        }
        return A < 2;
    }
}