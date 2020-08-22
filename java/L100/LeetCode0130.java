package L100;

public class LeetCode0130 {
    private int M;
    private int N;
    public void solve(char[][] board) {
        M = board.length;
        if (M == 0) {
            return;
        }
        N = board[0].length;
        for (int i = 0;i < M;++i) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][N - 1] == 'O') {
                dfs(board, i, N - 1);
            }
        }
        for (int j = 1;j < N - 1;++j) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[M - 1][j] == 'O') {
                dfs(board, M - 1, j);
            }
        }
        for (int i = 0;i < M;i++) {
            for (int j = 0;j < N;++j) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    public void dfs(char[][] board,int x,int y) {
        if (x < 0 || x >= M || y < 0 || y >= N || board[x][y] == 'X' || board[x][y] == 'A') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }

    public static void main(String[] args) {
        LeetCode0130 code = new LeetCode0130();
        char[][] board = {{'O','X','X','O','X'},{'X','O','O','X','O'},{'X','O','X','O','X'},
                          {'O','X','O','O','O'},{'X','X','O','X','O'}};
        code.solve(board);
    }
}