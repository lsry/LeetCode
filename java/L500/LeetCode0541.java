package L500;

public class LeetCode0541 {
    public String reverseStr(String s, int k) {
        if (s == null || s.length() < 2) {
            return s;
        }
        char[] arr = s.toCharArray();
        for (int i = 0;i < arr.length;i += 2 * k) {
            reverse(arr, i, i + k - 1);
        }
        return String.valueOf(arr);
    }

    private void reverse(char[] arr, int low, int high) {
        high = high < arr.length ? high : arr.length - 1;
        while (low < high) {
            char c = arr[low];
            arr[low] = arr[high];
            arr[high] = c;
            ++low;
            --high;
        }
    }
}