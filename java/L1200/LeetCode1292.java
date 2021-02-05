package L1200;

public class LeetCode1292 {
    public int maxSideLength(int[][] mat, int threshold) {
        int H = mat.length, W = mat[0].length;
        int[][] presum = new int[H + 1][W + 1];
        // 计算矩阵前缀和
        for (int i = 1;i <= H;++i) {
            for (int j = 1;j <= W;++j) {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] + mat[i - 1][j - 1] - presum[i - 1][j - 1];
            }
        }
        int maxSL = 0;
        for (int i = 1;i <= H;++i) {
            for (int j = 1;j <= W;++j) {
                int len = Math.min(H - i, W - j) + 1;
                if (mat[i - 1][j - 1] <= threshold) {
                    if (maxSL < 1) {
                        maxSL = 1;
                    }
                    maxSL = Math.max(maxSL, helper(presum, 1, len ,threshold,i,j));
                }
            }
        }
        return maxSL;
    }

    public int helper(int[][] presum,int left,int right,int hold,int x,int y) {
        if (left >= right) {
            return -1;
        }
        int middle = left + (right - left) / 2;
        // 求得当前位置处，middle 长度的方阵和
        int curSum = presum[x + middle][y + middle] - presum[x + middle][y - 1]
                   - presum[x - 1][y + middle] + presum[x - 1][y - 1];
        if (curSum == hold) {
            return middle + 1;
        } else if (curSum < hold) {
            int t = helper(presum, middle + 1, right, hold, x, y);
            if (t < middle + 1) {
                return middle + 1;
            } else {
                return t;
            }
        } else {
            return helper(presum, left, middle, hold, x, y);
        }
    }

    public static void main(String[] args) {
        int[][] test = new int[][]{{1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
        LeetCode1292 l23 = new LeetCode1292();
        System.out.println("#1:" + (3 == l23.maxSideLength(test, 6)));

        int[][] test2 = new int[][]{{28,39,98,91,7,99},{79,3,17,83,9,92},{81,73,42,27,67,70},{88,30,73,99,96,89},{27,59,0,1,65,79},{42,55,48,29,86,96}};
        System.out.println("#2:" + (6 == l23.maxSideLength(test2, 24829)));
        
    }
}