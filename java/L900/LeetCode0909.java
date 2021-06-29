package L900;

import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;

public class LeetCode0909 {
    public int snakesAndLadders(int[][] board) {
        final int N = board.length;
        int[] arr = new int[N * N];
        int index = 0;
        boolean flag = true;
        for (int i = N - 1;i >= 0;--i) {
            if (flag) {
                for (int j = 0;j < N;++j) {
                    arr[index] = board[i][j];
                    ++index;
                }
            } else {
                for (int j = N - 1;j >= 0;--j) {
                    arr[index] = board[i][j];
                    ++index;
                }
            }
            flag = !flag;
        }
        Deque<Integer> q1 = new LinkedList<>();
        HashMap<Integer,Integer> m1 = new HashMap<>();
        q1.offer(0);
        m1.put(0, 0);
        int ans = N * N;
        while (!q1.isEmpty()) {
            int cur = q1.poll();
            int step = m1.get(cur);
            if (cur == N * N - 1) {
                ans = Math.min(ans, step);
                continue;
            }
            for (int i = 1;i <= 6;++i) {
                int nx = cur + i;
                if (nx < N * N) {
                    if (arr[nx] != -1) {
                        nx = arr[nx] - 1;
                    } 
                    if (!m1.containsKey(nx)) {
                        m1.put(nx, step + 1);
                        q1.offer(nx);
                    }
                }
            }
        }
        return ans == N * N ? -1 : ans;
    }
}
