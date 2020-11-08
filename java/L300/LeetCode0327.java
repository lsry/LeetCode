package L300;

public class LeetCode0327 {
    public int countRangeSum(int[] nums, int lower, int upper) {
        long[] preSum = new long[nums.length + 1];
        for (int i = 0;i < nums.length;++i) {
            preSum[i + 1] = nums[i] + preSum[i];
        }
        return countRangeSumHalf(preSum, 0, preSum.length - 1, lower, upper);
    }
    private int countRangeSumHalf(long[] preSum, int left, int right, int lower, int upper) {
        if (left == right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int n1 = countRangeSumHalf(preSum, left, mid, lower, upper);
        int n2 = countRangeSumHalf(preSum, mid + 1, right, lower, upper);
        int ret = n1 + n2;
        int l = mid + 1;
        int r = mid + 1;
        for (int i = left;i <= mid;++i) {
            while (l <= right && preSum[l] - preSum[i] < lower) {
                ++l;
            }
            while (r <= right && preSum[r] - preSum[i] <= upper) {
                ++r;
            }
            ret += r - l;
        }
        long[] assit = new long[right - left + 1];
        int p = 0;
        l = left;
        r = mid + 1;
        while (l <= mid || r <= right) {
            if (l > mid) {
                assit[p] = preSum[r];
                ++r;
            } else if (r > right) {
                assit[p] = preSum[l];
                ++l;
            } else if (preSum[l] <= preSum[r]) {
                assit[p] = preSum[l];
                ++l;
            } else {
                assit[p] = preSum[r];
                ++r;
            }
            ++p;
        }
        for (int i = 0;i < assit.length;++i) {
            preSum[left + i] = assit[i];
        }
        return ret;
    }
}
