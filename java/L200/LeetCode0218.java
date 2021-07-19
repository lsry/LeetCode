package L200;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

public class LeetCode0218 {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        List<List<Integer>> res = new ArrayList<>();
        if (buildings == null || buildings.length == 0) {
            return res;
        }
        List<int[]> rheight = new ArrayList<>(buildings.length * 2);
        for (int[] building : buildings) {
            rheight.add(new int[]{building[0], -building[2]});
            rheight.add(new int[]{building[1], building[2]});
        }
        Collections.sort(rheight, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return a[1] - b[1];
            }
        });
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return b - a;
        });
        pq.offer(0);
        int height = 0;
        for (int[] rh : rheight) {
            if (rh[1] < 0) {
                pq.offer(-rh[1]);
            } else {
                pq.remove(rh[1]);
            }
            int ch = pq.peek();
            if (ch != height) {
                res.add(Arrays.asList(rh[0], ch));
                height = ch;
            }
        }
        return res;
    }
}