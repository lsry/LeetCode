package L000;

public class LeetCode0079 {
    public boolean search(char[][] board,int si,int sj,int index,char[] words){
        if (index == words.length){
            return true;
        } else if (si < 0 || si >= board.length || sj < 0 || sj >= board[0].length){
            return false;
        } else if (board[si][sj] != words[index]){
            return false;
        } else {
            index++;
            board[si][sj] = ' ';
            boolean res = search(board, si-1, sj, index, words) || search(board, si, sj-1, index, words) 
            || search(board, si+1, sj, index, words) || search(board, si, sj+1, index, words);
            board[si][sj] = words[index-1];
            return res;
        }
    }

    public boolean exist(char[][] board, String word) {
        if (word.length() <= 0){
            return true;
        } else if (board.length <= 0 || word.length() > board.length * board[0].length){
            return false;
        }
        int row = board.length;
        int column = board[0].length;
        char[] words = word.toCharArray();
        for (int r = 0;r < row;r++){
            for (int c = 0;c < column;c++){
                if (board[r][c] == words[0] && search(board, r, c, 0, words)){
                    return true;
                }
            }
        }
        return false;
    }

    private final static int[][] indics = new int[][]{{-1,0},{1,0},{0,-1},{0,1}};
    public boolean existDFS8ms(char[][] board, String word) {
        boolean[][] visits = new boolean[board.length][board[0].length];
        for (int i = 0;i < board.length;++i) {
            for (int j = 0;j < board[0].length;++j) {
                visits[i][j] = true;
                if (dfs(board, visits, i, j, word, 0)) {
                    return true;
                }
                visits[i][j] = false;
            }
        }
        return false;
    }
    private boolean dfs(char[][] board,boolean[][] visits,int x, int y,String word,int index) {
        if (index >= word.length() || (index == word.length() - 1 && word.charAt(index) == board[x][y])) {
            return true;
        }
        if (word.charAt(index) != board[x][y]) {
            return false;
        }
        for (int[] indic : indics) {
            int nx = indic[0] + x;
            int ny = indic[1] + y;
            if (nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length && !visits[nx][ny]) {
                visits[nx][ny] = true;
                if (dfs(board, visits, nx, ny, word, index + 1)) {
                    return true;
                } else {
                    visits[nx][ny] = false;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) {
        char[][] chs = new char[][]{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        LeetCode0079 ws = new LeetCode0079();
        System.out.println("ABCCED true: " + ws.exist(chs, "ABCCED"));
        System.out.println("SEE true: " + ws.exist(chs, "SEE"));
        System.out.println("ABCD false: " + ws.exist(chs, "ABCD"));
        System.out.println("\"\" true :" + ws.exist(chs, ""));
        System.out.println("AAA false: " + ws.exist(new char[][]{{'A','A'}}, "AAA"));
        char[][] chs2 = new char[][]{{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
        System.out.println("ABCESEEEFS true: " + ws.exist(chs2, "ABCESEEEFS"));
        char[][] chs3 = new char[][]{{'a','b','b','a','b'},{'a','a','b','b','a'},{'a','a','a','a','b'},
              {'a','a','a','b','a'},{'a','a','a','a','a'},{'a','b','a','b','b'},{'a','b','b','a','b'}};
        System.out.println("abbbbaababaa false: " + ws.exist(chs3, "abbbbaababaa"));
    }
}
