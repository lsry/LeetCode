package L600;

public class LeetCode0685 {
    class UnionFind {
        private int[] ids;
        private int[] weights;

        public UnionFind(int N) {
            ids = new int[N + 1];
            weights = new int[N + 1];
            for (int i = 0;i <= N;++i) {
                ids[i] = i;
                weights[i] = 1;
            }
        }

        public int find(int id) {
            while (id != ids[id]) {
                id = ids[id];
            }
            return id;
        }

        public void union(int p, int q) {
            int ip = find(p);
            int iq = find(q);
            if (ip != iq) {
                if (weights[p] < weights[q]) {
                    ids[ip] = iq;
                    weights[q] += weights[p];
                } else {
                    ids[iq] = ip;
                    weights[p] += weights[q];
                }
            }
        }

        public boolean connect(int p, int q) {
            return find(p) == find(q);
        }
    }
    public int[] findRedundantDirectedConnection(int[][] edges) {
        UnionFind uf = new UnionFind(edges.length);
        int[] parents = new int[edges.length + 1];
        for (int i = 0;i < parents.length;++i) {
            parents[i] = i;
        }
        int conflict = -1; // 当遇到含有两个父节点的结点时，当前边为冲突边
        int cycle = -1;   // 有公共根节点， 当前边为环边
        for (int i = 0;i < edges.length;++i) {
            if (parents[edges[i][1]] != edges[i][1]) {
                conflict = i;
            } else {
                parents[edges[i][1]] = edges[i][0];
                if (uf.connect(edges[i][0], edges[i][1])) {
                    cycle = i;
                } else {
                    uf.union(edges[i][0], edges[i][1]);
                }
            }
        }
        if (conflict > -1) {
            if (cycle > -1) {
                return new int[]{parents[edges[conflict][1]],edges[conflict][1]};
            } else {
                return new int[]{edges[conflict][0],edges[conflict][1]};
            }
        }
        if (cycle > -1) {
            return new int[]{edges[cycle][0],edges[cycle][1]};
        }
        return new int[]{};
    }
}
