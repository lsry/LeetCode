public class LeetCode0215 {
    public int findKthLargest(int[] nums, int k) {
        return findKthsmallest(nums, 0, nums.length - 1, nums.length - k);
    }

    public int findKthsmallest(int[] nums, int left, int right, int K) {
        if (left >= right) {
            return nums[left];
        }
        int q = partion(nums, left, right);
        if (q == K) {
            return nums[q];
        } else if (q < K) {
            return findKthsmallest(nums, q + 1, right, K);
        } else {
            return findKthsmallest(nums, left, q - 1, K);
        }
    }

    public int partion(int[] nums, int left, int right) {
        int l = left - 1;
        int key = nums[right];
        for (int r = left;r < right;++r) {
            if (nums[r] <= key) {
                int t = nums[r];
                nums[r] = nums[l + 1];
                nums[l + 1] = t;
                ++l;
            }
        }
        nums[right] = nums[l + 1];
        nums[l + 1] = key;
        return l + 1;
    }
}