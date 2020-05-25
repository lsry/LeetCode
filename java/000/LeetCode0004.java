public class LeetCode0004 {
    public double findMedianSortedArraysHalf(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        if (len1 == 0 && len2 == 0){
            return 0.0;
        }
        if (len1 > len2){
            int[] temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int len = len1;
            len1 = len2;
            len2 = len;
        }       
        int iMin = 0;
        int iMax = len1;
        int half = (len1 + len2 + 1) / 2 ;
        while (iMin <= iMax){
            int i = iMin + (iMax - iMin) / 2;
            int j = half - i;
            if (i > iMin && nums1[i-1] > nums2[j]){
                iMax = i - 1;
            } else if (i < iMax && nums2[j-1] > nums1[i]){
                iMin = i + 1;
            } else {
                int maxLeft = 0;
                if (i == 0){
                    maxLeft = nums2[j-1];
                } else if (j == 0){
                    maxLeft = nums1[i-1];
                } else {
                    maxLeft = Math.max(nums1[i-1], nums2[j-1]);
                }
                if ((len1 + len2) % 2 != 0){
                    return maxLeft;
                }
                int minRight = 0;
                if (i == len1){
                    minRight = nums2[j];
                } else if (j == len2){
                    minRight = nums1[i];
                } else {
                    minRight = Math.min(nums1[i], nums2[j]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2){
        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.length, n2 = nums2.length;
        if (n1 + n2 == 0) {
            return 0.0;
        }
        int left = 0, right = n1;
        int lx = 0, rn = 0;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (n1 + n2 + 1) / 2 - i;

            int lix = i - 1 < 0 ? Integer.MIN_VALUE : nums1[i - 1];
            int ljx = j - 1 < 0 ? Integer.MIN_VALUE : nums2[j - 1];
            int rin = i >= n1 ? Integer.MAX_VALUE : nums1[i];
            int rjn = j >= n2 ? Integer.MAX_VALUE : nums2[j];

            if (lix <= rjn) {
                lx = Math.max(lix, ljx);
                rn = Math.min(rin, rjn);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (n1 + n2) % 2 == 0 ? (lx + rn) / 2.0 : lx;
    }

    public static void main(String[] args) {
        LeetCode0004 l4 = new LeetCode0004();
        System.out.println(l4.findMedianSortedArrays(new int[]{}, new int[]{}));
        System.out.println(l4.findMedianSortedArrays(new int[]{}, new int[]{1}));
        System.out.println(l4.findMedianSortedArrays(new int[]{}, new int[]{1,2}));
        System.out.println(l4.findMedianSortedArrays(new int[]{1,3}, new int[]{2}));
        System.out.println(l4.findMedianSortedArrays(new int[]{1,3,5}, new int[]{2,4}));
        System.out.println(l4.findMedianSortedArrays(new int[]{2,6,8}, new int[]{1,5,7}));
    }
}