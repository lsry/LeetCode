public class R0803 {
    public int findMagicIndexIter(int[] nums) {
        for (int i = 0;i < nums.length;++i) {
            if (nums[i] == i) {
                return i;
            }
        }
        return -1;
    }

    public int findMagicIndex(int[] nums) {
        return binSearch(nums, 0, nums.length - 1);
    }

    public int binSearch(int[] nums, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = left + (right - left) / 2;
        int lv = binSearch(nums, left, mid - 1);
        if (lv != -1) {
            return lv;
        }
        if (nums[mid] == mid) {
            return mid;
        }
        return binSearch(nums, mid + 1, right);
    }
}