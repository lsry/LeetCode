package L700;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class LeetCode0743 {
    public int networkDelayTime(int[][] times, int n, int k) {
        if (times == null) {
            return 0;
        }
        HashMap<Integer, List<int[]>> map = new HashMap<>(n / 3 * 4);
        for (int[] time : times) {
            List<int[]> cList = map.getOrDefault(time[0], new ArrayList<>());
            cList.add(new int[]{time[1], time[2]});
            map.put(time[0], cList);
       }
       Deque<Integer> queue = new LinkedList<>();
       queue.offer(k);
       int[][] resTime = new int[2][n];
       Arrays.fill(resTime[0], -1);
       resTime[0][k - 1] = 0;
       resTime[1][k - 1] = 1;
       while (!queue.isEmpty()) {
           int cur = queue.poll();
           List<int[]> cList = map.get(cur);
           if (cList == null || cList.size() == 0) {
               continue;
           }
           for (int[] time : cList) {
               if (resTime[0][time[0] - 1] == -1) {
                   resTime[0][time[0] - 1] = resTime[0][cur - 1] + time[1];
               } else {
                   resTime[0][time[0] - 1] = Math.min(resTime[0][time[0] - 1], resTime[0][cur - 1] + time[1]);
               }
               resTime[1][time[0] - 1]++;
               if (resTime[1][time[0] - 1] < n) {
                   queue.offer(time[0]);
               }
           }
       }
       int t = -1;
       for (int rt : resTime[0]) {
           if (rt == -1) {
               return -1;
           }
           t = Math.max(t, rt);
       }
       return t;
    }
    
}