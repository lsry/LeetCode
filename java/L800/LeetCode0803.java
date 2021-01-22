package L800;

public class LeetCode0803 {
    private class UnionFind {
        private int[] ids, szs;

        public UnionFind (int N) {
            ids = new int[N];
            szs = new int[N];
            for (int i = 0;i < N;++i) {
                ids[i] = i;
                szs[i] = 1;
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
                if (szs[pid] <= szs[qid]) {
                    ids[pid] = qid;
                    szs[qid] += szs[pid];
                } else {
                    ids[qid] = pid;
                    szs[pid] += szs[qid];
                }
            }
        }

        public int getSize(int id) {
            int rid = find(id);
            return szs[rid];
        }
    }
    public int[] hitBricks(int[][] grid, int[][] hits) {
        final int M = grid.length, N = grid[0].length;
        final int HN = hits.length;

        int[][] copy = new int[M][N];
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                copy[i][j] = grid[i][j];
            }
        }

        for (int[] hit : hits) {
            copy[hit[0]][hit[1]] = 0;
        }

        UnionFind uf = new UnionFind(M * N + 1);
        for (int i = 0;i < N;++i) {
            if (copy[0][i] == 1) {
                uf.union(i, M * N);
            }
        }
        for (int i = 1;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (copy[i][j] == 1) {
                    if (j > 0 && copy[i][j - 1] == 1) {
                        uf.union(i * N + j, i * N + j - 1);
                    }
                    if (i > 0 && copy[i - 1][j] == 1) {
                        uf.union(i * N + j, (i - 1) * N + j);
                    }
                }
            }
        }
        
        int[] res = new int[HN];
        final int[][] dirs = new int[][]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = HN - 1;i >= 0;--i) {
            if (grid[hits[i][0]][hits[i][1]] == 0) {
                continue;
            }
            int osz = uf.getSize(M * N);
            if (hits[i][0] == 0) {
                uf.union(hits[i][1], M * N);
            }
            for (int[] dir : dirs) {
                int nx = hits[i][0] + dir[0];
                int ny = hits[i][1] + dir[1];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N && copy[nx][ny] == 1) {
                    uf.union(hits[i][0] * N + hits[i][1], nx * N + ny);
                }
            }
            int nsz = uf.getSize(M * N);
            res[i] = Math.max(0, nsz - osz - 1);
            copy[hits[i][0]][hits[i][1]] = 1;
        }
        return res;
    }
}
