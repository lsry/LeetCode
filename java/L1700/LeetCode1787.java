package L1700;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class LeetCode1787 {
    private static int MAXX = 1 << 10;
    private static int INF = Integer.MAX_VALUE / 2;
    public int minChanges(int[] nums, int k) {
        int n = nums.length;
        int[] f = new int[MAXX];
        Arrays.fill(f, INF);
        f[0] = 0;
        for (int i = 0;i < k;++i) {
            HashMap<Integer,Integer> map = new HashMap<>();
            int sz = 0;
            for (int j = i;j < n;j += k) {
                map.put(nums[j], map.getOrDefault(nums[j], 0) + 1);
                sz += 1;
            }

            int min = INF;
            for (int a = 0;a < f.length;++a) {
                if (f[a] < min) {
                    min = f[a];
                }
            }

            int[] g = new int[MAXX];
            Arrays.fill(g, min);
            for (int mask = 0;mask < MAXX;++mask) {
                for (Map.Entry<Integer,Integer> entry : map.entrySet()) {
                    int x = entry.getKey();
                    int count = entry.getValue();
                    g[mask] = Math.min(g[mask], f[x ^ mask] - count);
                }
            }
            for (int a = 0;a < g.length;++a) {
                g[a] += sz;
            }
            f = g;
        }
        return f[0];
    }
}
