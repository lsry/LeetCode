package L300;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode0368 {
    public List<Integer> largestDivisibleSubset(int[] nums) { 
        List<Integer> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        Arrays.sort(nums);
        int[][] dp = new int[nums.length][2];
        for (int i = 0;i < nums.length;++i) {
            dp[i][0] = 1;
            dp[i][1] = -1;
            for (int j = i - 1;j >= 0;--j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j][0] + 1 > dp[i][0]) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = j;
                    }
                }
            }
        }
        for (int i = nums.length - 1;i >= 0;--i) {
            if (dp[i][0] > res.size()) {
                res.clear();
                for (int j = i;j != -1;j = dp[j][1]) {
                    res.add(nums[j]);
                }
            }
        }
        return res;
    }
}
