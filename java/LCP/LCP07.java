package LCP;

import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class LCP07 {
    public int numWays(int n, int[][] relation, int k) {
        HashMap<Integer,List<Integer>> map = new HashMap<>(n);
        for (int[] edge : relation) {
            List<Integer> des = map.getOrDefault(edge[0], new ArrayList<>());
            des.add(edge[1]);
            map.put(edge[0], des);
        }

        int ans = 0;
        Deque<Integer> q = new LinkedList<>();
        q.offer(0);
        int index = 0;
        while (index < k && !q.isEmpty()) {
            int sz = q.size();
            for (int i = 0;i < sz;++i) {
                int d = q.poll();
                for (int other : map.getOrDefault(d, new ArrayList<>())) {
                    q.offer(other);
                }
            }
            ++index;
        }
        while (!q.isEmpty()) {
            int d = q.poll();
            if (d == n - 1) {
                ++ans;
            }
        }
        return ans;
    }
}