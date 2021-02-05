package L900;

/**
 * '0 , 1'
 * '0 / 1'
 * '1 \ 0'
 */
public class LeetCode0959 {
    private class UnionFind {
        private int count;
        private int[] ids, ranks;

        public UnionFind(int N) {
            this.count = N;
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

        public void union(int p, int q) {
            p = find(p);
            q = find(q);
            if (p != q) {
                if (ranks[p] <= ranks[q]) {
                    ids[p] = q;
                    if (ranks[p] == ranks[q]) {
                        ranks[q] += 1;
                    }
                } else {
                    ids[q] = p;
                }
                --count;
            }
        }

        public int getCount() {
            return this.count;
        }
    }

    private int getIndex(int x, int y, int pos, int N) {
        return 2 * (x * N + y) + pos;
    }

    public int regionsBySlashes(String[] grid) {
        final int N = grid.length;
        UnionFind uf = new UnionFind(2 * N * N);
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < N;++j) {
                char ch = grid[i].charAt(j);
                int id0 = getIndex(i, j, 0, N);
                int id1 = getIndex(i, j, 1, N);
                if (ch == ' ') {
                    uf.union(id0, id1);
                    if (i - 1 >= 0) {  // 和上方合并
                        uf.union(id0, getIndex(i - 1, j, 1, N));
                    }
                    if (j - 1 >= 0) {  // 和左边合并
                        char t = grid[i].charAt(j - 1);
                        if (t == ' ' || t == '\\') {
                            uf.union(id0, getIndex(i, j - 1, 0, N));
                        } else if (t == '/') {
                            uf.union(id0, getIndex(i, j - 1, 1, N));
                        }
                    }
                } else if (ch == '/') {
                    if (i - 1 >= 0) {
                        uf.union(id0, getIndex(i - 1, j, 1, N));
                    }
                    if (j - 1 >= 0) {
                        char t = grid[i].charAt(j - 1);
                        if (t == ' ' || t == '\\') {
                            uf.union(id0, getIndex(i, j - 1, 0, N));
                        } else if (t == '/') {
                            uf.union(id0, getIndex(i, j - 1, 1, N));
                        }
                    }
                } else if (ch == '\\') {
                    if (i - 1 >= 0) {
                        uf.union(id0, getIndex(i - 1, j, 1, N));
                    }
                    if (j - 1 >= 0) {
                        char t = grid[i].charAt(j - 1);
                        if (t == ' ' || t == '\\') {
                            uf.union(id1, getIndex(i, j - 1, 0, N));
                        } else if (t == '/') {
                            uf.union(id1, getIndex(i, j - 1, 1, N));
                        }
                    }
                }
            }
        }
        return uf.getCount();
    }
}
