package L1200;

public class LeetCode1208 {
    public int equalSubstring(String s, String t, int maxCost) {
        final int N = s.length();
        int remainCost = maxCost - Math.abs(s.charAt(0) - t.charAt(0));
        int len = 0;
        int l = 0, r = 1;
        for (;r < N;) {
            if (remainCost >= 0) {
                len = Math.max(len, r - l);
                remainCost -= Math.abs(s.charAt(r) - t.charAt(r));
                ++r;
            } else {
                remainCost += Math.abs(s.charAt(l) - t.charAt(l));
                ++l;
            }
        }
        if (remainCost >= 0) {
            len = Math.max(len, r - l);
        }
        return len;
    }
}
