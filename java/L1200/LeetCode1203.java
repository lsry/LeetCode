package L1200;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LeetCode1203 {

    private List<Integer> topSort(int[] deg, List<List<Integer>> graph, List<Integer> items) {
        Queue<Integer> queue = new LinkedList<>();
        for (int item : items) {
            if (deg[item] == 0) {
                queue.offer(item);
            }
        }
        List<Integer> res = new ArrayList<>(items.size());
        while (!queue.isEmpty()) {
            int u = queue.poll();
            res.add(u);
            List<Integer> edges = graph.get(u);
            for (int edge : edges) {
                --deg[edge];
                if (deg[edge] == 0) {
                    queue.offer(edge);
                }
            }
        }
        return res.size() == items.size() ? res : new ArrayList<>();
    }

    public int[] sortItems(int n, int m, int[] group, List<List<Integer>> beforeItems) {
        List<List<Integer>> groups = new ArrayList<>(n + m);
        List<List<Integer>> groupGraph = new ArrayList<>(n + m);
        List<Integer> ids = new ArrayList<>(n + m);
        for (int i = 0;i < n + m;++i) {
            groups.add(new ArrayList<>());
            groupGraph.add(new ArrayList<>());
            ids.add(i);
        }
        List<List<Integer>> itemGraph = new ArrayList<>(n);
        for (int i = 0;i < n;++i) {
            itemGraph.add(new ArrayList<>());
        }
        int[] groupDeg = new int[n + m];
        int[] itemDeg = new int[n];
        int leftId = m;
        for (int i = 0;i < group.length;++i) {
            if (group[i] == -1) {
                group[i] = leftId;
                ++leftId;
            }
            groups.get(group[i]).add(i);
        }
        for (int i = 0;i < n;++i) {
            int curGroupId = group[i];
            for (int item : beforeItems.get(i)) {
                int beforeGroupId = group[item];
                if (beforeGroupId == curGroupId) {
                    itemDeg[i] += 1;
                    itemGraph.get(item).add(i);
                } else {
                    groupDeg[curGroupId] += 1;
                    groupGraph.get(beforeGroupId).add(curGroupId);
                }
            }
        }
        List<Integer> groupSort = topSort(groupDeg, groupGraph, ids);
        if (groupSort.size() == 0) {
            return new int[]{};
        }
        int[] ans = new int[n];
        int index = 0;
        for (int curGroupId : groupSort) {
            int size = groups.get(curGroupId).size();
            if (size == 0) {
                continue;
            }
            List<Integer> gItems = topSort(itemDeg, itemGraph, groups.get(curGroupId));
            if (gItems.size() == 0) {
                return new int[]{};
            }
            for (int item : gItems) {
                ans[index] = item;
                ++index;
            }
        }
        return ans;
    }
}
