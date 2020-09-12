package L400;

public class LeetCode0486 {
    
    public boolean PredictTheWinnerRecur(int[] nums) {
        // 对于偶数个数字的数组，玩家1一定获胜。
        // 因为如果玩家1选择拿法A，玩家2选择拿法B，玩家1输了。
        // 则玩家1换一种拿法选择拿法B，因为玩家1是先手，所以玩家1一定可以获胜
        if (nums.length <= 2 || nums.length % 2 == 0){
            return true;
        }
        int[] prefixSum = new int[nums.length + 1];
        prefixSum[0] = 0;
        int[][] arr = new int[nums.length + 1][nums.length + 1];
        for (int i = 0;i < nums.length;i++){
            prefixSum[i + 1] = prefixSum[i] + nums[i];
            for (int j = 0;j < nums.length;j++){
                if (i == j){
                    arr[i + 1][j + 1] = nums[i];
                } else {
                    arr[i + 1][j + 1] = -1;
                }
            }
        }
        getPriorMaxScore(nums, 1, nums.length, arr, prefixSum);
        return arr[1][nums.length] * 2 >= prefixSum[nums.length];
    }

    /**
     * 获得先手最大分数 = 获得端点的数字 与 剩余选择的后手最大分数
     */
    public int getPriorMaxScore(int[] nums,int left,int right,int[][] arr,int[] preSum){
        if (left < 1 || left > right || right > nums.length){
            return 0;
        } if (arr[left][right] != -1){
            return arr[left][right];
        }
        arr[left][right] = Math.max(
            nums[left - 1] + (preSum[right] - preSum[left]) - getPriorMaxScore(nums,left + 1,right,arr,preSum)
            , 
            nums[right - 1] + (preSum[right - 1] - preSum[left - 1]) - getPriorMaxScore(nums,left,right - 1,arr,preSum)
            );
        return arr[left][right];
    }

    /**
     * dp[i][j] : 表示从 nums[i,...,j] 开始抓取中先手与后手获得分数之差
     * i == j : 显然差为 nums[i]
     * i < j: 先手A可获得 nums[i]后, 那么后手B在 num[i + 1, ... , j] 中变先手，获得分数差 dp[i + 1][j]，
     *        那么 A 的分数 为 nums[i] - dp[i + 1][j], 对于 A 选取 nums[i] 同理，
     *        此时 A 可获得分数差为两者中最大值； 
     */
    public boolean PredictTheWinner(int[] nums) {
        if (nums == null || nums.length % 2 == 0) {
            return true;
        }
        int[][] dp = new int[nums.length][nums.length];
        for (int r = 0;r < nums.length;++r) {
            dp[r][r] = nums[r];
        }
        for (int i = nums.length - 2;i >= 0;--i) {
            for (int j = i + 1;j < nums.length;++j) {
                dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][nums.length - 1] >= 0;
    }
}