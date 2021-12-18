package L400;

public class LeetCOde0419 {
    public int countBattleships(char[][] board) {
        int ans = 0;
        for (int i = 0;i < board.length;++i) {
            for (int j = 0;j < board[0].length;++j) {
                if (board[i][j] == 'X' && (i - 1 < 0 || board[i - 1][j] == '.')
                   && (j - 1 < 0 || board[i][j - 1] == '.')) {
                       ++ans;
                   } 
            }
        }
        return ans;
    }
}
