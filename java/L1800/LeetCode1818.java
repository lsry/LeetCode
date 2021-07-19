package L1800;

import java.util.TreeSet;

public class LeetCode1818 {
    private static final int MOD = 1_000_000_007;

    public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
        if (nums1 == null || nums1.length == 0) {
            return 0;
        }
        final int N = nums1.length;
        TreeSet<Integer> set = new TreeSet<>();
        long sum = 0L;
        for (int i = 0;i < N;++i) {
            set.add(nums1[i]);
            sum += Math.abs(nums1[i] - nums2[i]);
        }
        long ans = sum;
        for (int i = 0;i < N;++i) {
            long cur = sum - Math.abs(nums1[i] - nums2[i]);
            Integer v = set.ceiling(nums2[i]);
            if (v != null) {
                ans = Math.min(ans, cur + Math.abs(v - nums2[i]));
            }
            v = set.floor(nums2[i]);
            if (v != null) {
                ans = Math.min(ans, cur + Math.abs(v - nums2[i]));
            }
        }
        return (int)(ans % MOD);
    }
}