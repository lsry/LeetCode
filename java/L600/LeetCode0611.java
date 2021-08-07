package L600;

import java.util.Arrays;

public class LeetCode0611 {
    public int triangleNumber(int[] nums) {
        if (nums == null || nums.length < 3) {
            return 0;
        }
        Arrays.sort(nums);
        int ans = 0;
        for (int i = 0;i < nums.length - 2;++i) {
            for (int j = i + 1;j < nums.length - 1;++j) {
                int l = j + 1, r = nums.length - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (nums[mid] < nums[i] + nums[j]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                ans += l - j - 1;
            }
        }
        return ans;
    }
}