package L1300;

import java.util.Arrays;

public class LeetCode1371 {
    public int findTheLongestSubstring(String s) {
        int N = s.length();
        int[] pos = new int[32];
        Arrays.fill(pos, -1);
        pos[0] = 0;
        int ans = 0;
        int status = 0;
        for (int i = 0;i < N;++i) {
            char c = s.charAt(i);
            switch (c) {
                case 'a' : status ^= 1; break;
                case 'e' : status ^= 2; break;
                case 'i' : status ^= 4; break;
                case 'o' : status ^= 8; break;
                case 'u' : status ^= 16; break;
                default: break;
            }
            if (pos[status] >= 0) {
                ans = Math.max(ans,i + 1 - pos[status]);
            } else {
                pos[status] = i + 1;
            }
        }
        return ans;
    }
}