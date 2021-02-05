package L1300;

public class LeetCode1319 {
    private class UnionFind {
        private int count;
        private int[] ids, ranks;

        public UnionFind(int N) {
            count = N;
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

        public boolean union(int pid, int qid) {
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
                --count;
                return true;
            }
            return false;
        }
    }
    public int makeConnected(int n, int[][] connections) {
        UnionFind uf = new UnionFind(n);
        int remain = 0;
        for (int[] conn : connections) {
            if (uf.union(conn[0], conn[1])) {

            } else {
                ++remain;
            }
        }
        if (uf.count == 1) {
            return 0;
        }
        return remain >= uf.count - 1 ? uf.count - 1 : -1;
    }
}
