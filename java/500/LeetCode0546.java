

public class LeetCode0546 {
    public int removeBoxes(int[] boxes) {
        int[][][] dp = new int[boxes.length][boxes.length][boxes.length];
        return conCancel(boxes, 0, boxes.length - 1, 0, dp);
        
    }

    private int conCancel(int[] boxes, int left, int right, int num, int[][][] dp) {
        if (left > right) {
            return 0;
        }
        if (dp[left][right][num] != 0) {
            return dp[left][right][num];
        }
        while (right > left && boxes[right] == boxes[right - 1]) {
            --right;
            ++num;
        }
        dp[left][right][num] = conCancel(boxes, left, right - 1, 0, dp) + (num + 1) * (num + 1);
        for (int i = left;i < right;++i) {
            if (boxes[i] == boxes[right]) {
                int score = conCancel(boxes, left, i, num + 1, dp) + conCancel(boxes, i + 1, right - 1, 0, dp);
                dp[left][right][num] = Math.max(dp[left][right][num], score);
            }
        }
        return dp[left][right][num];
    }
}