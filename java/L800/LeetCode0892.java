package L800;

public class LeetCode0892 {
    /**
     * 每一个正方体贡献 6 个面，当相邻正方体接触时，会减少两个面
     */
    public int surfaceArea(int[][] grid) {
        int count = 0;
        int connect = 0;
        for (int i = 0;i < grid.length;++i) {
            for (int j = 0;j < grid[0].length;++j) {
                if (grid[i][j] > 0) {
                    connect += grid[i][j] - 1;
                }
                if (i > 0) {
                    connect += Math.min(grid[i-1][j], grid[i][j]);
                }
                if (j > 0) {
                    connect += Math.min(grid[i][j-1], grid[i][j]);
                }
                count += grid[i][j];
            }
        }
        return count * 6 - 2 * connect;
    }
}