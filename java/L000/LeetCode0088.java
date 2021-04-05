package L000;

public class LeetCode0088 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = 0, j = 0;
        int[] tmp = new int[m + n];
        int idx = 0;
        while (i < m || j < n) {
            if (i == m) {
                tmp[idx] = nums2[j];
                ++j;
            } else if (j == n) {
                tmp[idx] = nums1[i];
                ++i;
            } else if (nums1[i] < nums2[j]) {
                tmp[idx] = nums1[i];
                ++i;
            } else {
                tmp[idx] = nums2[j];
                ++j;
            }
            ++idx;
        }
        for (i = 0;i < m + n;++i) {
            nums1[i] = tmp[i];
        }
    }
}
