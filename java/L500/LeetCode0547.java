package L500;

public class LeetCode0547 {
    private class UnionFind {
        private int[] ids;
        private int[] weights;
        private int count;

        public UnionFind(int N) {
            weights = new int[N];
            ids = new int[N];
            count = N;
            for (int i = 0;i < N;++i) {
                ids[i] = i;
                weights[i] = 1;
            }
        }

        public int getCount() {
            return count;
        }

        public int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        public void union(int p, int q) {
            int i1 = find(p);
            int i2 = find(q);
            if (i1 != i2) {
                if (weights[i1] >= weights[i2]) {
                    weights[i1] += weights[q];
                    ids[i2] = i1;
                } else {
                    weights[i2] += weights[p];
                    ids[i1] = i2;
                }
                this.count -= 1;
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        final int N = isConnected.length;
        UnionFind uf = new UnionFind(N);
        for (int i = 0;i < N;++i) {
            for (int j = i + 1;j < N;++j) {
                if (isConnected[i][j] == 1) {
                    uf.union(i, j);
                }
            }
        }
        return uf.getCount();
    }
}
