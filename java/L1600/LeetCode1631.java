package L1600;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode1631 {
    private class UnionFind {
        private int[] ids, ranks;

        public UnionFind (int N) {
            ids = new int[N];
            ranks = new int[N];
            for (int i = 0;i < N;++i) {
                ids[i] = i;
            }
        }

        public int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        public void union(int pid, int qid) {
            pid = find(pid);
            qid = find(qid);
            if (pid != qid) {
                if (ranks[pid] <= ranks[qid]) {
                    ids[pid] = qid;
                    if (ranks[pid] == ranks[qid]) {
                        ranks[qid] += 1;
                    }
                } else {
                    ids[qid] = pid;
                }
            }
        }
    }
    public int minimumEffortPath(int[][] heights) {
        int RN = heights.length, CN = heights[0].length;
        List<int[]> edges = new ArrayList<>(RN * CN);
        for (int i = 0;i < RN;++i) {
            for (int j = 0;j < CN;++j) {
                if (i + 1 < RN) {
                    edges.add(new int[]{i * CN + j, (i + 1) * CN + j, Math.abs(heights[i][j] - heights[i + 1][j])});
                }
                if (j + 1 < CN) {
                    edges.add(new int[]{i * CN + j, i * CN + j + 1, Math.abs(heights[i][j] - heights[i][j + 1])});
                }
            }
        }
        Collections.sort(edges, (e1, e2) -> {
            return e1[2] - e2[2];
        });
        int ans = -1;
        UnionFind uf = new UnionFind(RN * CN);
        for (int[] edge : edges) {
            uf.union(edge[0], edge[1]);
            if (uf.find(0) == uf.find((RN - 1) * CN + CN - 1)) {
                ans = edge[2];
                break;
            }
        }
        return ans;
    }
}
