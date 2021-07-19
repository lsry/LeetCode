package L200;

public class LeetCode0275 {
    public int hIndex(int[] citations) {
        if (citations == null || citations.length == 0) {
            return 0;
        }
        int N = citations.length;
        int low = 1, high = N;
        while (low < high) {
            int mid = (low + high) / 2;
            if (citations[N - mid] >= mid) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low - 1;
    }

    public static void main(String[] args) {
        LeetCode0275 code = new LeetCode0275();
        code.hIndex(new int[]{1});
    }
}