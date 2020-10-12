package L700;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LeetCode0710 {
}

/**
 * 主要在于禁止数字超过总数一定的百分比后，就应该统计允许的数字，减少计算量
 */
class Solution {
    private final int N;
    private Set<Integer> banned;
    private List<Integer> allowed;

    public Solution(int N, int[] blacklist) {
        this.N = N;
        banned = new HashSet<>();
        for (int x : blacklist) {
            banned.add(x);
        }
        allowed = new ArrayList<>();
        if (banned.size() >= (N / 3)) {
            for (int i = 0;i < N;++i) {
                if (!banned.contains(i)) {
                    allowed.add(i);
                }
            }
        }
    }
    
    public int pick() {
        if (allowed.size() > 0) {
            int index = (int)(allowed.size() * (Math.random() / Math.nextDown(1.0)));
            return allowed.get(index);
        } else {
            int cur = 0;
            do {
                double f = Math.random() / Math.nextDown(1.0);
                cur = (int) (N * f);
            } while (banned.contains(cur));
            return cur;
        }
    }
}