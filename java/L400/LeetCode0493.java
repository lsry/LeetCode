package L400;

public class LeetCode0493 {
    public int reversePairs(int[] nums) {
        return divid(nums, 0, nums.length - 1);
    }

    private int divid(int[] nums, int left, int right) {
        if (left >= right) {
            return 0;
        }
        int mid = left + (right - left) / 2;
        int ans = divid(nums, left, mid) + divid(nums, mid + 1, right);
        int a = left, b = mid + 1;
        while (a <= mid) {
            while (b <= right && (long)nums[a] > 2 * (long)nums[b]) {
                ++b;
            }
            ans += b - mid - 1;
            ++a;
        }
        int[] trr = new int[right - left + 1];
        int index = 0;
        int l = left, r = mid + 1;
        while (l <= mid || r <= right) {
            if (l > mid) {
                trr[index] = nums[r];
                ++r;
            } else if (r > right) {
                trr[index] = nums[l];
                ++l;
            } else if (nums[l] <= nums[r]) {
                trr[index] = nums[l];
                ++l;
            } else {
                trr[index] = nums[r];
                ++r;
            }
            ++index;
            
        }
        for (int i = left;i <= right;++i) {
            nums[i] = trr[i - left];
        }
        return ans;
    }

    public static void main(String[] args) {
        LeetCode0493 code = new LeetCode0493();
        code.reversePairs(new int[]{1,3,2,3,1});
    }
}
