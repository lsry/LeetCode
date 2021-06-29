package L800;

import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;

public class LeetCode0815 {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        final int N = routes.length;
        HashMap<Integer,List<Integer>> stops = new HashMap<>();
        for (int i = 0;i < N;++i) {
            for (int stop : routes[i]) {
                List<Integer> buses = stops.getOrDefault(stop, new ArrayList<>());
                buses.add(i);
                stops.put(stop, buses);
            }
        }
        if (!stops.containsKey(source) || !stops.containsKey(target)) {
            return -1;
        }
        int[] busCount = new int[N];
        Deque<Integer> q = new LinkedList<>();
        for (int bus : stops.get(source)) {
            q.offer(bus);
            busCount[bus] = 1;
        }
        HashSet<Integer> set = new HashSet<>();
        set.add(source);
        while (!q.isEmpty()) {
            int bus = q.poll();
            for (int stop : routes[bus]) {
                if (stop == target) {
                    return busCount[bus];
                }
                if (!set.contains(stop)) {
                    set.add(stop);
                    if (stops.containsKey(stop)) {
                        for (int b : stops.get(stop)) {
                            if (busCount[b] == 0) {
                                q.offer(b);
                                busCount[b] = busCount[bus] + 1;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
}
