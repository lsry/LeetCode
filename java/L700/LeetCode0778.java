package L700;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class LeetCode0778 {
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

    private static final int[][] dirs = new int[][]{{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

    public int getIndex(int x, int y, int N) {
        return x * N + y + 1;
    }

    /**
     * 建立两个超源点p0, pN，其中左上角和 p0 相连，右下角和 pN 相连，最后判断这两个源点是否在同一个连通分量中
     */
    public int swimInWater(int[][] grid) {
        final int N = grid.length;
        List<int[]> points = new ArrayList<>(N * N);
        for (int i = 0;i < N;++i) {
            for (int j = 0;j < N;++j) {
                points.add(new int[]{i, j, grid[i][j]});
            }
        }
        Collections.sort(points, (p1, p2) -> {
            return p1[2] - p2[2];
        });
        UnionFind uf = new UnionFind(N * N + 2);
        uf.union(0, 1);
        uf.union(N * N, N * N + 1);
        int ans = 0;
        boolean[][] flags = new boolean[N][N];
        for (int[] point : points) {
            flags[point[0]][point[1]] = true;
            for (int[] dir : dirs) {
                int nx = dir[0] + point[0];
                int ny = dir[1] + point[1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && flags[nx][ny] == true) {
                    uf.union(getIndex(point[0], point[1], N), getIndex(nx, ny, N));
                }
            }
            if (uf.find(0) == uf.find(N * N + 1)) {
                ans = point[2];
                break;
            }
        }
        return ans;
    }
}
