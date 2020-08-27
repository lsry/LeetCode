package L200;

public class LeetCode0289 {
    // 非原址操作
    public void gameOfLifeOutPlace(int[][] board) {
        int[][] panel = new int[board.length][board[0].length];
        for (int i = 0;i < board.length;i++){
            for (int j = 0;j < board[0].length;j++){
                int num = liveNum(board,i,j);
                if (board[i][j] == 1){
                    panel[i][j] = (num == 2 || num == 3) ? 1 : 0;
                } else {
                    panel[i][j] = (num == 3) ? 1 : 0;                   
                }
            }
        }
        for (int i = 0;i < board.length;i++){
            for (int j = 0;j < board[0].length;j++){
                board[i][j] = panel[i][j];
            }
        }
    }

    public int liveNum(int[][] board,int x,int y){
        int nums = 0;
        for (int i = x - 1,j = y - 1;j <= y + 1;j++){
            if (i >= 0 && j >= 0 && i < board.length && j < board[0].length && board[i][j] == 1){
                nums++;
            }
        }
        for (int i = x + 1,j = y - 1;j <= y + 1;j++){
            if (i >= 0 && j >= 0 && i < board.length && j < board[0].length && board[i][j] == 1){
                nums++;
            }
        }
        if (x >= 0 && y - 1 >= 0 && x < board.length && y - 1 < board[0].length && board[x][y - 1] == 1){
            nums++;
        }
        if (x >= 0 && y + 1 >= 0 && x < board.length && y + 1 < board[0].length && board[x][y + 1] == 1){
            nums++;
        }
        return nums;
    }

    /**
     * 多状态法
     * 1-1 ：1
     * 1-0 ：-1
     * 0-0 ：0
     * 0-1 ：2
     */
    private static final int[][] nei = new int[][]{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    public void gameOfLife(int[][] board) {
        int M = board.length, N = board[0].length;
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                int live = 0;
                for (int[] pos : nei) {
                    int nx = i + pos[0];
                    int ny = j + pos[1];
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && (board[nx][ny] == -1 || board[nx][ny] == 1)) {
                        ++live;
                    }
                }
                if (board[i][j] == -1 || board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        board[i][j] = -1;
                    } else {
                        board[i][j] = 1;
                    }
                } else if (live == 3) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0;i < M;++i) {
            for (int j = 0;j < N;++j) {
                if (board[i][j] > 0) {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
    }
}