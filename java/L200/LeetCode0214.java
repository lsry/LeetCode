package L200;

import java.util.Arrays;

public class LeetCode0214 {
    /**
     * 判断 [0, r] 的回文性，找到最长的，然后将最后的逆序添加到前面
     * Time Limit Exceed
     * O(n^2)
     */
    public String shortestPalindromeN2(String s) {
        if (s== null || s.length() <= 1) {
            return s;
        }
        int r = 0;
        for (int i = s.length() - 1;i >= 1;--i) {
            if (isPalindrome(s, 0, i)) {
                r = i;
            }
        }
        if (r >= s.length() - 1) {
            return s;
        }
        return new StringBuilder(s.substring(r + 1)).reverse().append(s).toString();
    }

    private boolean isPalindrome(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }

    public String shortestPalindrome(String s) {
        if (s== null || s.length() <= 1) {
            return s;
        }
        final int SN = s.length();
        int[] next = new int[SN];
        Arrays.fill(next, -1);
        for (int i = 1;i < SN;++i) {
            int j = next[i - 1];
            while (j != -1 && s.charAt(i) != s.charAt(j + 1)) {
                j = next[j];
            }
            if (s.charAt(i) == s.charAt(j + 1)) {
                next[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = SN - 1;i >= 0;--i) {
            while (best != -1 && s.charAt(best + 1) != s.charAt(i)) {
                best = next[best];
            }
            if (s.charAt(best + 1) == s.charAt(i)) {
                ++best;
            }
        }
        String add = best == SN - 1 ? "" : s.substring(best + 1);
        return new StringBuilder(add).reverse().append(s).toString();
    }
}