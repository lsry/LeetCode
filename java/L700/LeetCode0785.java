package L700;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode0785 {
    private static final int UNCOLORED = 0;
    private static final int RED = 1;
    private static final int GREEN = 2;
    public boolean isBipartite(int[][] graph) {
        int[] colors = new int[graph.length];
        for (int i = 0;i < graph.length;++i) {
            if (colors[i] == UNCOLORED) {
                colors[i] = RED;
                Queue<Integer> qu = new LinkedList<>();
                qu.offer(i);
                while (!qu.isEmpty()) {
                    int x = qu.poll();
                    int color = colors[x] == RED ? GREEN : RED;
                    for (int n : graph[x]) {
                        if (colors[n] == UNCOLORED) {
                            colors[n] = color;
                            qu.offer(n);
                        } else if (colors[n] != color) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
}