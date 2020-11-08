package L300;

import java.util.HashSet;

public class LeetCode0349 {
    public int[] intersection(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length) {
            return intersection(nums2, nums1);
        }
        HashSet<Integer> set1 = new HashSet<>(nums1.length);
        for (int n1 : nums1) {
            set1.add(n1);
        }
        HashSet<Integer> res = new HashSet<>();
        for (int n2 : nums2) {
            if (set1.contains(n2)) {
                res.add(n2);
            }
        }
        return res.stream().mapToInt(K -> K).toArray();
    }
}
