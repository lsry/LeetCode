package L900;

public class LeetCode0912 {
    /**
     * Quick Sort
     */

    private int partition(int[] nums, int left, int right) {
        int l = left - 1;
        int i = left;
        while (i < right) {
            if (nums[i] < nums[right]) {
                l++;
                int t = nums[i];
                nums[i] = nums[l];
                nums[l] = t; 
            }
            ++i;
        }
        int t = nums[right];
        nums[right] = nums[l+1];
        nums[l+1] = t;
        return l + 1;
    }

    public void quickSort(int[] nums,int left,int right) {
        if (left >= right) {
            return;
        }
        int p = partition(nums, left, right);
        quickSort(nums, left, p - 1);
        quickSort(nums, p + 1, right);
    }

    public int[] sortArray(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
        return nums;
    }
}