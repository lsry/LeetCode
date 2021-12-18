package L700;

public class LeetCode0794 {
    public boolean validTicTacToe(String[] board) {
        int nx = 0, no = 0;
        for (String s : board) {
            for (char c : s.toCharArray()) {
                if (c == 'X') {
                    ++nx;
                } else if (c == 'O') {
                    ++no;
                }
            }   
        }
        if (!(nx == no || nx == no + 1)) {
            return false;
        }
        boolean x = false, o = false;
        for (int i = 0;i < 3;++i) {
            if (board[i].equals("XXX")) {
                x = true;
            } else if (board[i].equals("OOO")) {
                o = true;
            }
            if (board[0].charAt(i) == board[1].charAt(i) && board[0].charAt(i) == board[2].charAt(i)) {
                if (board[0].charAt(i) == 'X') {
                    x = true;
                } else if (board[0].charAt(i) == 'O') {
                    o = true;
                }
            }
        }
        if (x && o) {
            return false;
        }
        if ((board[0].charAt(0) == board[1].charAt(1) && board[0].charAt(0) == board[2].charAt(2)) ||
            (board[0].charAt(2) == board[1].charAt(1) && board[0].charAt(2) == board[2].charAt(0))) {
                if (board[1].charAt(1) == 'X') {
                    x = true;
                } else if (board[1].charAt(1) == 'O') {
                    o = true;
                }
        }
        return x || o ? (x && nx == no + 1) || (o && nx == no) : true;
    }
}