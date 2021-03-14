package L100;

import java.util.Arrays;

public class LeetCode0132 {
    public boolean isPalindrome(String s,int start,int end){
        int left = start,right = end;
        while (left < right){
            if (s.charAt(left) != s.charAt(right)){   
                return false;
            } 
            left++;
            right--;
        }
        return true;
    }

    public int minCutHelper(String s,int start,int end,int[][] arr, boolean[][] palia){
        if (arr[start][end] != -1){
            return arr[start][end];
        } else if (palia[start][end]){
            arr[start][end] = 0;
            return 0;
        }
        int min = end - start + 1;
        for (int i = start;i < end;i++){
            int temp = minCutHelper(s, start, i, arr, palia) + minCutHelper(s, i+1, end, arr, palia) + 1;
            if (temp < min){
                min = temp;
            }
        }
        arr[start][end] = min;
        return min;
    }

    public int minCutRecur(String s) {
        int length = s.length();
        int[][] arr = new int[length][length];
        boolean[][] palia = new boolean[length][length];
        for (int i = 0;i < length;i++){
            Arrays.fill(palia[i], true);
            for (int j = 0;j < length;j++){
                if (i == j){
                    arr[i][j] = 0;
                } else {
                    arr[i][j] = -1;
                }
            }
        }
        for (int i = length - 1;i >= 0;--i) {
            for (int j = i + 1;j < length;++j) {
                palia[i][j] = palia[i + 1][j - 1] && s.charAt(i) == s.charAt(j);
            }
        }
        return minCutHelper(s, 0, s.length() - 1, arr, palia);
        
    }

    /**
     * dp[i] = min{dp[j]} + 1， 0 <= j < i， s[j + 1][i] 回文
     */
    public int minCut(String s) {
        final int N = s.length();
        int[] dp = new int[N];
        boolean[][] palia = new boolean[N][N];
        Arrays.fill(dp, N + 1);
        for (int i = 0;i < N;++i) {
            Arrays.fill(palia[i], true);
        }
        for (int i = N - 1;i >= 0;--i) {
            for (int j = i + 1;j < N;++j) {
                palia[i][j] = palia[i + 1][j - 1] && s.charAt(i) == s.charAt(j);
            }
        }
        for (int i = 0;i < N;++i) {
            if (palia[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0;j < i;++j) {
                    if (palia[j + 1][i]) { // 当前位置能否划分，取决于后面是否回文
                        dp[i] = Math.min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[N - 1];
    }

    public static void main(String[] args) {
        String str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        LeetCode0132 l32 = new LeetCode0132();
        System.out.println(l32.minCut(str));
    }
}