package L600;

public class LeetCode0684 {
    private class UnionFind {
        private int[] ids, ranks;

        public UnionFind(int N) {
            ids = new int[N];
            ranks = new int[N];
            for (int i = 0;i < N;++i) {
                ids[i] = i;
                ranks[i] = 1;
            }
        }

        public int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        public void union(int p, int q) {
            int pid = find(p);
            int qid = find(q);
            if (pid != qid) {
                if (ranks[pid] <= ranks[qid]) {
                    ids[pid] = qid;
                } else {
                    ids[qid] = pid;
                }
                if (ranks[pid] == ranks[qid]) {
                    ranks[qid] += 1;
                }
            }
        }

        public boolean isConnected(int p, int q) {
            return find(p) == find(q);
        }
    }

    public int[] findRedundantConnection(int[][] edges) {
        UnionFind uf = new UnionFind(edges.length + 1);
        for (int[] edge : edges) {
            if (!uf.isConnected(edge[0], edge[1])) {
                uf.union(edge[0], edge[1]);
            } else {
                return edge;
            }
        }
        return new int[0];
    }
}
