package LCP;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class LCP13 {
    private static final int[][] indics = new int[][]{{0,-1},{0,1},{1,0},{-1,0}};
    private int M;
    private int N;
    public int minimalSteps(String[] maze) {
        M = maze.length;
        N = maze[0].length();
        int[] sp = new int[]{-1,-1}, tp = new int[]{-1,-1};
        List<int[]> buttons = new ArrayList<>();
        List<int[]> stones = new ArrayList<>();
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                char c = maze[i].charAt(j);
                if (c == 'M') {
                    buttons.add(new int[]{i, j});
                } else if (c == 'O') {
                    stones.add(new int[]{i, j});
                } else if (c == 'S') {
                    sp = new int[]{i, j};
                } else if (c == 'T') {
                    tp = new int[]{i, j};
                }
            }
        }
        final int nb = buttons.size();
        final int ns = stones.size();
        // 起始点到各个点最短距离
        int[][] startDist = bfs(sp,maze);
        if (nb == 0) {
            return startDist[tp[0]][tp[1]];
        }
        // 机关之间及到起点，终点的最短距离
        int[][] dist = new int[nb][nb + 2];
        for (int i = 0;i < nb;++i) {
            Arrays.fill(dist[i], -1);
        }
        int[][][] dd = new int[nb][][];
        for (int i = 0;i < nb;++i) {
            int[][] arr = bfs(buttons.get(i), maze);
            dd[i] = arr;
            dist[i][nb + 1] = arr[tp[0]][tp[1]];
        }
        for (int i = 0;i < nb;++i) {
            int tmp = -1; // S -> O -> Mi to get min(S,Mi)
            for (int k = 0;k < ns;++k) {
                int[] mid = stones.get(k);
                if (dd[i][mid[0]][mid[1]] != -1 && startDist[mid[0]][mid[1]] != -1) {
                    if (tmp == -1 || tmp > dd[i][mid[0]][mid[1]] + startDist[mid[0]][mid[1]]) {
                        tmp = dd[i][mid[0]][mid[1]] + startDist[mid[0]][mid[1]];
                    }
                }
            }
            dist[i][nb] = tmp;
            for (int j = i + 1;j < nb;++j) {
                int mn = -1; // Mi -> O -> Mj to get min(Mi,Mj)
                for (int k = 0;k < ns;++k) {
                    int[] mid = stones.get(k);
                    if (dd[i][mid[0]][mid[1]] != -1 && dd[j][mid[0]][mid[1]] != -1) {
                        if (mn == -1 || mn > dd[i][mid[0]][mid[1]] + dd[j][mid[0]][mid[1]]) {
                            mn = dd[i][mid[0]][mid[1]] + dd[j][mid[0]][mid[1]];
                        }
                    }
                }
                dist[i][j] = mn;
                dist[j][i] = mn;
            }
        }
        for (int i = 0;i < nb;++i) {
            if (dist[i][nb] == -1 || dist[i][nb + 1] == -1) {
                return -1;
            }
        }
        int[][] dp = new int[1 << nb][nb];
        for (int i = 0;i < (1 << nb);++i) {
            Arrays.fill(dp[i], -1);
        }
        // 从起始点到任意一个机关的初始状态
        for (int i = 0;i < nb;++i) {
            dp[1 << i][i] = dist[i][nb];
        }
        for (int mask = 1;mask < (1 << nb);++mask) {
            for (int i = 0;i < nb;++i) {
                if ((mask & (1 << i)) != 0) { // 当前状态包含 i
                    for (int j = 0;j < nb;++j) {
                        if ((mask & (1 << j)) == 0) { // 不包含 j
                            int next = mask | (1 << j);
                            if (dp[next][j] == -1 || dp[next][j] > dp[mask][i] + dist[i][j]) {
                                dp[next][j] = dp[mask][i] + dist[i][j];
                            }
                        }
                    }
                }
            }
        }
        int ret = -1;
        int finalMask = (1 << nb) - 1;
        for (int i = 0;i < nb;++i) {
            if (ret == -1 || ret > dp[finalMask][i] + dist[i][nb + 1]) {
                ret = dp[finalMask][i] + dist[i][nb + 1];
            }
        }
        return ret;
    }

    private int[][] bfs(int[] point,String[] maze) {
        int[][] ret = new int[M][N];
        for (int i = 0;i < ret.length;++i) {
            Arrays.fill(ret[i], -1);
        }
        ret[point[0]][point[1]] = 0;
        Queue<int[]> qu = new LinkedList<>();
        qu.offer(point);
        while (!qu.isEmpty()) {
            int[] cur = qu.poll();
            for (int[] index : indics) {
                int nx = cur[0] + index[0];
                int ny = cur[1] + index[1];
                if (check(nx, ny) && maze[nx].charAt(ny) != '#' && ret[nx][ny] == -1) {
                    qu.offer(new int[]{nx,ny});
                    ret[nx][ny] = ret[cur[0]][cur[1]] + 1;
                }
            }
        }
        return ret;
    }

    private boolean check(int nx, int ny) {
        return nx >= 0 && nx < M && ny >= 0 && ny < N;
    }
}