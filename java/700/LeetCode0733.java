import java.util.LinkedList;
import java.util.Queue;

public class LeetCode0733 {
    private static final int[][] indics = new int[][]{{-1,0},{0,-1},{1,0},{0,1}};
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color == newColor) {
            return image;
        }
        Queue<int[]> qu = new LinkedList<>();
        qu.offer(new int[]{sr,sc});
        while (!qu.isEmpty()) {
            int[] cur = qu.poll();
            image[cur[0]][cur[1]] = newColor;
            for (int[] index : indics) {
                int nx = cur[0] + index[0];
                int ny = cur[1] + index[1];
                if (nx >= 0 && nx < image.length && ny >= 0 && ny < image[0].length && image[nx][ny] == color) {
                    qu.offer(new int[]{nx,ny});
                }
            }
        }
        return image;
    }
}