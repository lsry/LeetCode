package L1200;

public class LeetCode1232 {
    public boolean checkStraightLine(int[][] coordinates) {
        int y2_y1 = coordinates[1][1] - coordinates[0][1];
        int x2_x1 = coordinates[1][0] - coordinates[0][0];
        for (int i = 2;i < coordinates.length;++i) {
            int y3_y1 = coordinates[i][1] - coordinates[0][1];
            int x3_x1 = coordinates[i][0] - coordinates[0][0];
            if (y2_y1 * x3_x1 != x2_x1 * y3_y1) {
                return false;
            }
        }
        return true;
    }
}
