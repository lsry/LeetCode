package L000;

public class LeetCode0034 {
    /**
     * 首先用二分查找找到对应值的位置，然后向两边扩展即可
     */
    public int[] searchRangeExtend(int[] nums, int target) {
        int[] res = new int[]{-1,-1};
        int left = 0;
        int right = nums.length;
        int mid = 0;
        while (left < right){
            mid = left + (right - left) / 2;
            if (target == nums[mid]){
                break;
            } else if (target > nums[mid]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left < right){
            res[0] = mid;
            res[1] = mid;
            while (res[0] - 1 >= 0 && nums[res[0] - 1] == target){
                res[0]--;
            }
            while (res[1] + 1 < nums.length && nums[res[1]+ 1] == target){
                res[1]++;
            }
        }
        return res;
    }

    /**
     * 用二叉搜索找最左边与最右边索引
     */
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[]{-1,-1};
        int l = 0, r = nums.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (l - 1 >= 0 && nums[l - 1] == target) {
            res[1] = l - 1;
        } else {
            return res;
        }
        l = 0;
        r = nums.length - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (r + 1 < nums.length && nums[r + 1] == target) {
            res[0] = r + 1;
        }
        return res;
    }
}