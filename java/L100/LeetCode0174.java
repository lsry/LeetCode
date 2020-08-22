package L100;

public class LeetCode0174 {
    /**
     * 每一格记录进入格子需要的点数
     */
    public int calculateMinimumHP(int[][] dungeon) {
        int M = dungeon.length, N = dungeon[0].length;
        for (int i = M - 1;i >= 0;--i) {
            for (int j = N - 1;j >= 0;--j) {
                if (i == M - 1 && j == N - 1) {
                    if (dungeon[i][j] > 0) {
                        dungeon[i][j] = 1;
                    } else {
                        dungeon[i][j] = 1  - dungeon[i][j];
                    }
                } else {
                    int min = Integer.MAX_VALUE;
                    // 计算进入下一格需要的最少点数
                    if (i + 1 < M) {
                        min = Math.min(min, dungeon[i + 1][j]);
                    } 
                    if (j + 1 < N) {
                        min = Math.min(min, dungeon[i][j + 1]);
                    }
                    if (dungeon[i][j] > 0) { // 查看当前格子是否能补充足够的点数
                        int x = min - dungeon[i][j];
                        dungeon[i][j] = x > 0 ? x : 1;
                    } else {
                        dungeon[i][j] = min - dungeon[i][j];
                    }
                }
            }
        }
        return dungeon[0][0];
    }

    public static void main(String[] args) {
        LeetCode0174 code = new LeetCode0174();
        System.out.println("1: " + code.calculateMinimumHP(new int[][]{{0,0}}));
    }
}