package L700;

import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;

public class LeetCode0773 {
    private static final int[][] indics = new int[][]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    public int slidingPuzzle(int[][] board) {
        String s = boardString(board);
        if (s.equals("123450")) {
            return 0;
        }
        Deque<String> q1 = new LinkedList<>();
        q1.offer(s);
        HashMap<String,Integer> m1 = new HashMap<>();
        m1.put(s, 0);
        Deque<String> q2 = new LinkedList<>();
        q2.offer("123450");
        HashMap<String,Integer> m2 = new HashMap<>();
        m2.put("123450", 0);
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int r = -1;
            if (q1.size() <= q2.size()) {
                r = update(q1, m1, m2);
            } else {
                r = update(q2, m2, m1);
            }
            if (r != - 1) {
                return r;
            }
        }
        return -1;
    }

    private String boardString(int[][] board) {
        StringBuilder sBuilder = new StringBuilder();
        for (int[] bs : board) {
            for (int b : bs) {
                sBuilder.append(b);
            }
        }
        return sBuilder.toString();
    }

    private int update(Deque<String> q, HashMap<String,Integer> m1, HashMap<String,Integer> m2) {
        String cur = q.poll();
        int[] zero = new int[]{0, 0};
        int[][] board = new int[2][3];
        for (int i = 0;i < 2;++i) {
            for (int j = 0;j < 3;++j) {
                board[i][j] = cur.charAt(i * 3 + j) - '0';
                if (board[i][j] == 0) {
                    zero[0] = i;
                    zero[1] = j;
                }
            }
        }
        for (int[] index : indics) {
            int x = zero[0] + index[0];
            int y = zero[1] + index[1];
            if (x >= 0 && x < 2 && y >= 0 && y < 3) {
                int t = board[x][y];
                board[x][y] = board[zero[0]][zero[1]];
                board[zero[0]][zero[1]] = t;
                String next = boardString(board);
                if (!m1.containsKey(next)) {
                    if (m2.containsKey(next)) {
                        return m1.get(cur) + 1 + m2.get(next);
                    } else {
                        q.offer(next);
                        m1.put(next, m1.get(cur) + 1);
                    }
                }
                t = board[x][y];
                board[x][y] = board[zero[0]][zero[1]];
                board[zero[0]][zero[1]] = t;
            }
        }
        return -1;
    }
}
