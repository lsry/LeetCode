public class LeetCode0287 {
    public int findDuplicate(int[] nums) {
        int left = 0, right = nums.length - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int cnt = 0;
            for (int num : nums) {
                if (num <= mid) {
                    ++cnt;
                }
            }
            // 多的那一边存在重复数
            if (cnt <= mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
}