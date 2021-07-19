package review;

public class R53I {
    public int search(int[] nums, int target) {
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
            return 0;
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
        return res[1] - res[0] + 1;
    }
}