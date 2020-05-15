public class LeetCode0069 {
    public int mySqrtTLE(int x) {
        int root = 0;
        while (root * root <= x) {
            ++root;
        }
        return root - 1;
    }

    public int mySqrt(int x) {
        if (x == 0) {
            return x;
        }
        int left = 0, right = x;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (mid * mid / mid != mid || mid * mid > x) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return (right * right / right != right || right * right > x) ? left : right;
    }
}