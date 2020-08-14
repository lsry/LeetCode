package L000;

public class LeetCode0055 {
    public boolean canJump(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return true;
        }
        int[] can = new int[nums.length];
        helper(nums, 0, can);
        return can[0] == 1;
    }
    private int helper(int[] nums,int index,int[] can) {
        if (index >= nums.length || can[index] == -1) {
            return -1;
        }
        if (index == nums.length - 1 || can[index] == 1) {
            can[index] = 1;
            return 1;
        }
        int isArrive = -1;
        for (int i = nums[index];i >= 1;--i) {
            isArrive = helper(nums, index + i, can);
            if (isArrive == 1) {
                break;
            }
        }
        can[index] = isArrive;
        return isArrive;
    }
}