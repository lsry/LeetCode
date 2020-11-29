package L1100;

import java.util.LinkedList;
import java.util.Queue;

public class LeetCode1162 {
    public int maxDistance39ms(int[][] grid) {
        int maxDistance = -1;

        for (int i = 0;i < grid.length;i++){
            for (int j = 0;j < grid[0].length;j++){
                if (grid[i][j] == 0){
                    int distance = circle(grid,i,j);
                    if (distance > maxDistance){
                        maxDistance = distance;
                    }
                }
            }
        }

        return maxDistance;
    }

    public int circle(int[][] grid,int x,int y) {
        int distance = -1;
        for (int dis = 1;
             x - dis >= 0 || y - dis >= 0 || x + dis < grid.length || y + dis < grid[0].length;
             dis++){
            int minDis = grid.length + grid[0].length + 1;
            int topLeftX = x - dis,topLeftY = y - dis;
            int topRightX = x - dis,topRightY = y + dis;
            int bottomLeftX = x + dis,bottomLeftY = y - dis;
            int bottomRightX = x + dis,bottomRightY = y + dis;
            // top cross
            boolean flag = false;
            for (int i = topLeftX,j = topLeftY;j <= topRightY;j++){
                if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == 1){
                    flag = true;
                    int d = Math.abs(x - i) + Math.abs(y - j);
                    if (d < minDis){
                        minDis = d;
                    }
                }
            }

            // bottom cross
            for (int i = bottomLeftX,j = bottomLeftY;j <= bottomRightY;j++){
                if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == 1){
                    flag = true;
                    int d = Math.abs(x - i) + Math.abs(y - j);
                    if (d < minDis){
                        minDis = d;
                    }
                }
            }

            // left vertical
            for (int i = topLeftX,j = topLeftY;i <= bottomLeftX;i++){
                if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == 1){
                    flag = true;
                    int d = Math.abs(x - i) + Math.abs(y - j);
                    if (d < minDis){
                        minDis = d;
                    }
                }
            }

            // rigth vertical
            for (int i = topRightX,j = topRightY;i <= bottomRightX;i++){
                if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == 1){
                    flag = true;
                    int d = Math.abs(x - i) + Math.abs(y - j);
                    if (d < minDis){
                        minDis = d;
                    }
                }
            }

            if (flag){
                if (minDis != (grid.length + grid[0].length + 1)){
                    distance = minDis;
                }
                break;
            }
        }

        return distance;
    }

    public int maxDistance(int[][] grid) {
        Queue<int[]> qu = new LinkedList<>();
        for (int i = 0;i < grid.length;++i) {
            for (int j = 0;j < grid[0].length;++j) {
                if (grid[i][j] == 1) {
                    qu.offer(new int[]{i,j});
                }
            }
        }
        int distance = -1;
        int[][] dir = new int[][]{{-1,0},{0,-1},{0,1},{1,0}};
        while (!qu.isEmpty()) {
            int[] point = qu.poll();
            for (int[] ar : dir) {
                int nx = point[0] + ar[0];
                int ny = point[1] + ar[1];
                if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[0].length || grid[nx][ny] != 0) {
                    continue;
                }
                grid[nx][ny] = grid[point[0]][point[1]] + 1;
                if (distance < grid[nx][ny]) {
                    distance = grid[nx][ny] - 1;
                }
                qu.offer(new int[]{nx,ny});
            }
        }
        return distance;
    }
}