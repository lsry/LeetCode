import java.util.Arrays;

public class LeetCode1024 {
    /**
     * 0-1 package 
     */
    public int videoStitching01(int[][] clips, int T) {
        if (clips == null || clips.length == 0) {
            return -1;
        }
        Arrays.sort(clips,(a,b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return a[1] - b[1];
            }
        });
        if (clips[0][0] > 0 || T < clips[0][0] || T > clips[clips.length - 1][1]) {
            return -1;
        }
        int[][] dp = new int[clips.length][T+1];
        dp[0][0] = 0;
        for (int i = 1;i <= T;++i) {
            if (i < clips[0][0] || i > clips[0][1]) {
                dp[0][i] = Integer.MAX_VALUE - 3000;
            } else if (i == clips[0][0]) {
                dp[0][i] = 0;
            }  else {
                dp[0][i] = 1;
            }
        }
        for (int ix = 1;ix < clips.length;++ix) {
            for (int iy = 0;iy <= T;++iy) {
                if (iy <= clips[ix][0] || iy > clips[ix][1]) {
                    dp[ix][iy] = dp[ix - 1][iy];
                } else {
                    int cur = dp[ix][clips[ix][0]] + 1;
                    dp[ix][iy] = Math.min(cur, dp[ix - 1][iy]);
                }
            }
        }
        if (dp[clips.length - 1][T] >= Integer.MAX_VALUE - 3000 || dp[clips.length - 1][T] < 0) {
            return -1;
        } else {
            return dp[clips.length - 1][T];
        }
    }

    /**
     * 贪心
     * 首先计算对于每一个时间点来说，能达到的最右时间点
     * 考虑对于每一个时间点，更新每次能到达的最右时间点，遍历完成后，能到达 T，则成功
     * 其次记录上一个最右时间点，若当前时间点大于等于上一个时间，则计数加一
     */
    public int videoStitching(int[][] clips, int T) {
        int[] rends = new int[T];
        for (int[] clip : clips) {
            if (clip[0] < T) {
                rends[clip[0]] = Math.max(rends[clip[0]], clip[1]);
            }
        }
        int last = 0, pre = 0, res = 0;
        for (int i = 0;i < T;++i) {
            last = Math.max(last, rends[i]);
            if (last == i) {  // 当前最远到 i，无法再往下移动
                return -1;
            }
            if (i == pre) {
                ++res;
                pre = last;
            }
        }
        return res;
    }
}