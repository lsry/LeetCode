package L800;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0802 {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> res = new ArrayList<>();
        if (graph == null || graph.length == 0) {
            return res;
        }
        int[] color = new int[graph.length];
        for (int i = 0;i < graph.length;++i) {
            if (dfs(graph, i, color)) {
                res.add(i);
            }
        }
        return res;
    }

    private boolean dfs(int[][] graph, int index, int[] color) {
        if (color[index] == 1) {
            return false;
        }
        if (color[index] == 2) {
            return true;
        }
        color[index] = 1;
        for (int e : graph[index]) {
            if (!dfs(graph, e, color)) {
                return false;
            }
        }
        color[index] = 2;
        return true;
    }
}
