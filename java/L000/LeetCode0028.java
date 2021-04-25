package L000;

public class LeetCode0028 {
    public int strStr(String haystack, String needle) {
        if (needle == null || needle.length() == 0) {
            return 0;
        }
        if (haystack == null || haystack.length() < needle.length()) {
            return -1;
        }
        final int hn = haystack.length(), nn = needle.length();
        int[] next = new int[nn];
        next[0] = -1;
        for (int i = 1;i < nn;++i) {
            int j = i - 1;
            while (j != 0 && needle.charAt(i - 1) != needle.charAt(next[j])) {
                j = next[j];
            }
            next[i] = next[j] + 1;
        }
        int a = 0, b = 0;
        while (a < hn && b < nn) {
            if (b == -1 || haystack.charAt(a) == needle.charAt(b)) {
                ++a;
                ++b;
            } else {
                b = next[b];
            }
        }
        return b == nn ? a - b : -1;
    }
}
