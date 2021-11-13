package L300;

public class LeetCode0367 {
    public boolean isPerfectSquare(int num) {
        for (int low = 1, high = 46340;low <= high;) {
            int mid = (low + high) / 2;
            int squar = mid * mid;
            if (squar == num) {
                return true;
            } else if (squar < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
}