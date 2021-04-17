package L000;

public class LeetCode0081 {
    public boolean search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        for (int l = 0, r = nums.length - 1;l <= r;) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return true;
            }
            if (nums[m] < nums[r]) {
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (nums[m] > nums[l]) {
                if (target < nums[m] && target >= nums[l]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else if (nums[m] == nums[l] && nums[m] == nums[r]) {
                for (int i = l;i <= r;++i) {
                    if (nums[i] == target) {
                        return true;
                    }
                }
                return false;
            } else if (nums[m] == nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return false;
    }
}
