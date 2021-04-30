package L400;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class LeetCode0403 {
    public boolean canCross(int[] stones) {
        if (stones == null || stones.length < 2) {
            return true;
        }
        if (stones[0] + 1 < stones[1]) {
            return false;
        }
        final int N = stones.length;
        List<Set<Integer>> steps = new ArrayList<>(N);
        for (int i = 0;i < N;++i) {
            steps.add(new HashSet<>());
        }
        steps.get(1).add(stones[1] - stones[0]);
        for (int i = 1;i < N - 1;++i) {
            Set<Integer> csSet = steps.get(i);
            if (csSet.isEmpty()) {
                continue;
            }
            for (int s : csSet) {
                int dir = stones[i] + s;
                for (int j = i + 1;j < N;++j) {
                    if (stones[j] == dir - 1 || stones[j] == dir || stones[j] == dir + 1) {
                        steps.get(j).add(stones[j] - stones[i]);
                    } else if (stones[j] > dir + 1) {
                        break;
                    }
                }
            }
        }
        return !steps.get(N - 1).isEmpty();
    }
}
