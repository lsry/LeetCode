package review;

public class R51 {
    public int reversePairs(int[] nums) {
        return mergeSort(nums, 0, nums.length - 1);
    }

    public int mergeSort(int[] nums,int l1,int r1) {
        if (l1 >= r1) {
            return 0;
        }
        int mid = (l1 + r1) / 2;
        return mergeSort(nums, l1, mid) + mergeSort(nums, mid + 1, r1) + merge(nums,l1,mid,r1);
    }

    public int merge(int[] nums,int l1, int mid,int r2) {
        int n1 = mid - l1 + 1;
        int n2 = r2 - mid;
        int[] arr1 = new int[n1];
        int[] arr2 = new int[n2];
        for (int i = 0;i < n1;++i) {
            arr1[i] = nums[l1 + i];
        }
        for (int i = 0;i < n2;++i) {
            arr2[i] = nums[mid + 1 + i];
        }
        int reverse = 0;
        int i = 0, j = 0, k = l1;
        while (i < n1 && j < n2) {
            if (arr1[i] <= arr2[j]) {
                reverse += j;
                nums[k] = arr1[i];
                ++i;
            } else {               
                nums[k] = arr2[j];
                ++j;
            }
            ++k;
        }
        if (i < n1) {           
            while (i < n1) {
                reverse += j;
                nums[k] = arr1[i];
                ++i;
                ++k;
            }
        }
        if (j < n2) {
            while (j < n2) {
                nums[k] = arr2[j];
                ++j;
                ++k;
            }
        }
        return reverse;
    }
}