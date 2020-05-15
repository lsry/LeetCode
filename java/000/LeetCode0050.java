public class LeetCode0050 {
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        } else if (n == 1) {
            return x;
        } else if (x == 0.0) {
            return n < 0 ? Double.POSITIVE_INFINITY : x;
        } else if (n == -1) {
            return 1 / x;
        } else if (n % 2 == 0) {
            double d = myPow(x, n / 2);
            return d * d;
        } else {
            return x * myPow(x, n - 1);
        }
    }

    public static void main(String[] args) {
        LeetCode0050 l50 = new LeetCode0050();
        System.out.println(l50.myPow(2, 10) == Math.pow(2, 10));
        System.out.println(l50.myPow(2.1, 3) == Math.pow(2.1, 3));
        System.out.println(l50.myPow(2, -10) == Math.pow(2, -10));
        System.out.println(l50.myPow(2, Integer.MIN_VALUE) == Math.pow(2, Integer.MIN_VALUE));
        System.out.println(l50.myPow(2, Integer.MAX_VALUE) == Math.pow(2, Integer.MAX_VALUE));
        System.out.println(l50.myPow(0, -1) == Math.pow(0,-1));
        System.out.println(l50.myPow(0, 5) == Math.pow(0,5));
        System.out.println(l50.myPow(0, 0) == Math.pow(0,0));
        System.out.println(l50.myPow(-5,7) == Math.pow(-5,7));
        System.out.println(l50.myPow(-10.2,-12) == Math.pow(-10.2,-12)); // 有误差
    }
}