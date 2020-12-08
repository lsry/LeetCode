package L300;

public class LeetCode0321 {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        if (nums1.length < nums2.length) {
            return maxNumber(nums2, nums1, k);
        }
        int n1_min = Math.min(nums1.length, k);
        int[] res = new int[k];
        int[] temp = new int[k];
        for (int i = 0;i <= n1_min;++i) {
            if (k - i >= 0 && k - i <= nums2.length) {
                int[] arr1 = maxIArr(nums1, i);
                int[] arr2 = maxIArr(nums2, k - i);
                int index = 0;
                int a = 0, b = 0;
                while (a < arr1.length || b < arr2.length) {
                    if (a >= arr1.length) {
                        temp[index] = arr2[b];
                        ++b;
                    } else if (b >= arr2.length) {
                        temp[index] = arr1[a];
                        ++a;
                    } else if (arr1[a] > arr2[b]) {
                        temp[index] = arr1[a];
                        ++a;
                    } else if (arr2[b] > arr1[a]) {
                        temp[index] = arr2[b];
                        ++b;
                    } else {
                        if (compareIndex(arr1, a, arr2, b) > 0) {
                            temp[index] = arr1[a];
                            ++a;
                        } else {
                            temp[index] = arr2[b];
                            ++b;
                        }
                    }
                    ++index;
                }
            }
            if (smaller(res, temp)) {
                for (int p = 0;p < res.length;++p) {
                    res[p] = temp[p];
                }
            }
            pArr(res);
        }
        return res;
    }

    private int compareIndex(int[] arr1, int i1, int[] arr2, int i2) {
        while (i1 < arr1.length && i2 < arr2.length) {
            if (arr1[i1] != arr2[i2]) {
                return arr1[i1] - arr2[i2];
            }
            ++i1;
            ++i2;
        }
        return (arr1.length - i1) - (arr2.length - i2);
    }

    private int[] maxIArr(int[] nums, int k) {
        int[] trr = new int[k];
        int top = -1;
        int remain = nums.length - k;
        for (int i = 0;i < nums.length;++i) {
            while (top >= 0 && top < k && nums[i] > trr[top] && remain > 0) {
                top--;
                --remain;
            }
            if (top < k - 1) {
                ++top;
                trr[top] = nums[i];
            } else {
                --remain;
            }
        }
        return trr;
    }

    private boolean smaller(int[] arr1, int[] arr2) {
        for (int i = 0;i < arr1.length;++i) {
            if (arr1[i] != arr2[i]) {
                return Integer.compare(arr1[i], arr2[i]) < 0;
            }
        }
        return false;
    }

    private void pArr(int[] arr) {
        for (int a : arr) {
            System.out.print(a + "\t");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LeetCode0321 code = new LeetCode0321();
        int[] a1 = new int[]{2,5,6,4,4,0};
        int[] a2 = new int[]{7,3,8,0,6,5,7,6,2};
        code.pArr(code.maxNumber(a1, a2, 15));
    }
}