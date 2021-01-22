package L1500;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode1584 {
    private class UnionFind {
        private int[] ids, ranks;

        public UnionFind(int N) {
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

        public boolean union(int p, int q) {
            int pid = find(p);
            int qid = find(q);
            if (pid != qid) {
                if (ranks[pid] <= ranks[qid]) {
                    ids[pid] = qid;
                    if (ranks[pid] == ranks[qid]) {
                        ranks[qid] += 1;
                    }
                } else {
                    ids[qid] = pid;
                }
                return true;
            }
            return false;
        }
    }

    private class Edge {
        public int a, b, len;

        public Edge(int a, int b, int len) {
            this.a = a;
            this.b = b;
            this.len = len;
        }
    }

    private int getLen(int[][] points, int a, int b) {
        return Math.abs(points[a][0] - points[b][0]) + Math.abs(points[a][1] - points[b][1]);
    }

    public int minCostConnectPoints(int[][] points) {
        final int N = points.length;
        List<Edge> edges = new ArrayList<>(N);
        for (int i = 0;i < N;++i) {
            for (int j = i + 1;j < N;++j) {
                edges.add(new Edge(i, j, getLen(points, i, j)));
            }
        }
        Collections.sort(edges, (a, b) -> {
            return a.len - b.len;
        });
        UnionFind uf = new UnionFind(N);
        int cost = 0, num = 1;
        for (Edge edge : edges) {
            if (uf.union(edge.a, edge.b)) {
                cost += edge.len;
                num++;
                if (num == N) {
                    break;
                }
            }
        }
        return cost;
    }
}
