import java.util.LinkedList;
import java.util.Queue;

public class LeetCode0994 {
    /**
     * 多源广度优先搜索
     */
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0) {
            return -1;
        }
        int notRot = 0;
        Queue<int[]> rot = new LinkedList<>();
        for (int i = 0;i < grid.length;++i) {
            for (int j = 0;j < grid[0].length;++j) {
                if (grid[i][j] == 2) { // 记录初始条件下腐烂橘子的位置
                    rot.offer(new int[]{i,j}); // 记录新鲜橘子数目
                } else if (grid[i][j] == 1) {
                    notRot++;
                }
            }
        }
        if (notRot == 0) {
            return 0;
        }
        int round = -1;
        int[][] indices = new int[][]{{-1,0},{0,-1},{1,0},{0,1}};
        while (!rot.isEmpty()) {
            // 从上一分钟被腐烂的橘子开始腐烂它们周围的橘子
            for (int size = rot.size();size > 0;--size) {
                int[] node = rot.poll();
                for (int i = 0;i < indices.length;++i) {
                    int x = node[0] + indices[i][0];
                    int y = node[1] + indices[i][1];
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        --notRot;
                        rot.offer(new int[]{x,y});
                    }
                }
            }
            ++round;
        }
        return (notRot == 0) ? round : -1;
    }

    public static void main(String[] args) {
        int[][] grid = new int[][]{{2,1,1},{1,1,0},{0,1,1}};
        LeetCode0994 ld = new LeetCode0994();
        ld.orangesRotting(grid);
    }
}