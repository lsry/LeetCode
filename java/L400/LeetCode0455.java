package L400;

import java.util.Arrays;

public class LeetCode0455 {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int si = 0;
        int ans = 0;
        for (int gi = 0;gi < g.length;++gi) {
            while (si < s.length && s[si] < g[gi]) {
                ++si;
            }
            if (si >= s.length) {
                break;
            }
            ++si;
            ++ans;
        }
        return ans;
    }
}
