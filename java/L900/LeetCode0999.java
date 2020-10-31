package L900;

public class LeetCode0999 {
    public int numRookCaptures(char[][] board) {
        int cap = 0;
        for (int i = 0;i < board.length;++i) {
            for (int j = 0;j < board[0].length;++j) {
                if (board[i][j] == 'R') {
                    int k = 1;
                    while (i - k >= 0 && board[i-k][j] != 'B') {
                        if (board[i-k][j] == 'p') {
                            cap++;
                            break;
                        }
                        k++;
                    }
                    k = 1;
                    while (i + k < board.length && board[i+k][j] != 'B') {                       
                        if (board[i+k][j] == 'p') {
                            cap++;
                            break;
                        }
                        k++;
                    }
                    k = 1;
                    while (j + k < board.length && board[i][j+k] != 'B') {                       
                        if (board[i][j+k] == 'p') {
                            cap++;
                            break;
                        }
                        k++;
                    }
                    k = 1;
                    while (j - k >= 0 && board[i][j-k] != 'B') {
                        if (board[i][j-k] == 'p') {
                            cap++;
                            break;
                        }
                        k++;
                    }
                }
            }  
        }
        return cap;
    }
}