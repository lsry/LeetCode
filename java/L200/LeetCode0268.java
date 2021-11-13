package L200;

public class LeetCode0268 {
    public int missingNumber(int[] nums) {
        for (int i = 0;i < nums.length;) {
            if (nums[i] == i) {
                ++i;
            } else if (nums[i] == nums.length || nums[i] == -1) {
                nums[i] = -1;
                ++i;
            } else {
                int id = nums[i];
                int t = nums[id];
                nums[id] = id;
                nums[i] = t;
            }
        }
        for (int i = 0;i < nums.length;++i) {
            if (nums[i] == -1) {
                return i;
            }
        }
        return nums.length;
    }
}
