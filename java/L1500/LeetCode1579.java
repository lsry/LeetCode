package L1500;

public class LeetCode1579 {
    private class UnionFind {
        private final int N;
        private int count;
        private int[] ids, ranks;

        public UnionFind(int N) {
            this.N = N;
            ids = new int[N];
            ranks = new int[N];
            clear();
        }

        public void clear() {
            this.count = N;
            for (int i = 0;i < N;++i) {
                ids[i] = i;
                ranks[i] = 0;
            }
        }

        public int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        public boolean union(int pid, int qid) {
            pid = find(pid);
            qid = find(qid);
            if (pid == qid) {
                return false;
            }
            if (ranks[pid] <= ranks[qid]) {
                ids[pid] = qid;
                if (ranks[pid] == ranks[qid]) {
                    ranks[qid] += 1;
                }
            } else {
                ids[qid] = pid;
            }
            this.count--;
            return true;
        }

        public int getCount() {
            return this.count;
        }
    }
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind uf = new UnionFind(n);
        int dec = 0;
        for (int[] edge : edges) {
            if (edge[0] == 3) {
                if (!uf.union(edge[1]-1, edge[2]-1)) {
                    ++dec;
                }
            }
        }
        for (int[] edge : edges) {
            if (edge[0] == 1) {
                if (!uf.union(edge[1]-1, edge[2]-1)) {
                    ++dec;
                }
            }
        }
        if (uf.getCount() != 1) {
            return -1;
        }
        uf.clear();
        for (int[] edge : edges) {
            if (edge[0] == 3) {
                uf.union(edge[1]-1, edge[2]-1);
            }
        }
        for (int[] edge : edges) {
            if (edge[0] == 2) {
                if (!uf.union(edge[1]-1, edge[2]-1)) {
                    ++dec;
                }
            }
        }
        return uf.getCount() == 1 ? dec : -1;
    }
}
