package L900;

public class LeetCode0947 {
    private class UnionFind {
        private int count;
        private int[] ids, rank;

        public UnionFind(int N) {
            count = 0;
            ids = new int[20002];
            rank = new int[20002];
            for (int i = 0;i < 20002;++i) {
                ids[i] = -1;
            }
        }

        public int find(int id) {
            if (ids[id] == -1) {
                ids[id] = id;
                ++count;
            }
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        public void union(int p, int q) {
            int pid = find(p);
            int qid = find(q);

            if (pid != qid) {
                if (rank[pid] < rank[qid]) {
                    ids[pid] = qid;
                } else {
                    ids[qid] = pid;
                }
                if (rank[pid] == rank[qid]) {
                    rank[qid] += 1;
                }
                --count;
            }
        }

        public int getCount() {
            return this.count;
        }
    }
    public int removeStones(int[][] stones) {
        UnionFind uf = new UnionFind(stones.length);
        for (int[] stone : stones) {
            uf.union(stone[0], stone[1] + 10001);
        }
        return stones.length - uf.getCount();
    }
}
