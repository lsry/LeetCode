package L800;

public class LeetCode0852 {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 1, high = arr.length - 1;
        while (low < high) {
            int mid = low + high + 1 >> 1;
            if (arr[mid - 1] < arr[mid]) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
}
