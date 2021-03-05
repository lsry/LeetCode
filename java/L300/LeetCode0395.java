package L300;

public class LeetCode0395 {
    public int longestSubstring(String s, int k) {
        return divid(s, 0, s.length() - 1, k);
    }

    private int divid(String s, int l, int r, int k) {
        if (r - l + 1 < k) {
            return 0;
        }
        int[] cnt = new int[26];
        for (int i = l;i <= r;++i) {
            cnt[s.charAt(i) - 'a'] += 1;
        }
        int split = 0;
        for (int i = 0;i < 26;++i) {
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }
        if (split == 0) {
            return r - l + 1;
        }
        int res = 0;
        for (int i = l;i <= r;) {
            while (i <= r && s.charAt(i) == split) {
                ++i;
            }
            if (i > r) {
                break;
            }
            int start = i;
            while (i <= r && s.charAt(i) != split) {
                ++i;
            }
            res = Math.max(res, divid(s, start, i - 1, k));
        }
        return res;
    }
}
