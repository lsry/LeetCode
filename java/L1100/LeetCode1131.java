package L1100;

public class LeetCode1131 {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE, min3 = Integer.MAX_VALUE, min4 = Integer.MAX_VALUE;
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE, max4 = Integer.MIN_VALUE;
        for (int i = 0;i < arr1.length;++i) {
            int sum = arr1[i] + arr2[i] + i;
            min1 = sum < min1 ? sum : min1;
            max1 = sum > max1 ? sum : max1;

            sum = arr1[i] - arr2[i] - i;
            min2 = sum < min2 ? sum : min2;
            max2 = sum > max2 ? sum : max2;

            sum = arr1[i] - arr2[i] + i;
            min3 = sum < min3 ? sum : min3;
            max3 = sum > max3 ? sum : max3;

            sum = arr1[i] + arr2[i] - i;
            min4 = sum < min4 ? sum : min4;
            max4 = sum > max4 ? sum : max4;
        }
        return Math.max(Math.max(max1 - min1, max2 - min2), Math.max(max3 - min3, max4 - min4));
    }
}