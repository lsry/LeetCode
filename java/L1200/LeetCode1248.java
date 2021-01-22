public class LeetCode1248 {
    public int numberOfSubarrays(int[] nums, int k) {
        int nsub = 0;
        int curOdd = 0;
        for (int left = 0, right = -1;left < nums.length && right < nums.length;) {           
            while (right < nums.length && curOdd < k) {
                ++right;
                if (right < nums.length && nums[right] % 2 != 0) {
                    curOdd++;
                }
            }
            if (curOdd < k) {
                break;
            }
            int nl = 0;
            for (int i = left;i < right && nums[i] % 2 == 0;++i) {
                ++nl;
            }
            int nr = 0;
            for (int i = right + 1;i < nums.length && nums[i] % 2 == 0;++i) {
                ++nr;
            }
            nsub += 1 + nl + nr + nl * nr;
            left += nl + 1;
            right += nr;
            --curOdd;
        }
        return nsub;
    }
}