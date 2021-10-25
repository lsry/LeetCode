package review;

public class R69 {
    public int peakIndexInMountainArray(int[] arr) {
        for (int i = 1, j = arr.length - 2; i <= j;) {
            int m = i + (j - i) / 2;
            if (arr[m] > arr[m - 1] && arr[m] > arr[m + 1]) {
                return m;
            } else if (arr[m - 1] < arr[m] && arr[m] < arr[m + 1]) {
                i = m + 1;
            } else {
                j = m - 1;
            }
        }
        return -1;
    }
}