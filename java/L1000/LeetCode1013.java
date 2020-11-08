package L1000;

public class LeetCode1013 {
    public boolean canThreePartsEqualSum(int[] A) {
        if (A.length < 3) {
            return false;
        }
        int sum = 0;
        for (int a : A) {
            sum += a;
        }
        if (sum % 3 != 0) {
            return false;
        }
        sum /= 3;
        int index = 1;
        // 找开头子数组
        for (int s = sum - A[0];index < A.length && s != 0;++index) {
            s -= A[index];
        }
        int i1 = index - 1;
        if (index >= A.length) {
            return false;
        }
        // 找中间子数组
        ++index;
        for (int s = sum - A[index-1];index < A.length && s != 0;++index) {
            s -= A[index];
        }
        return i1 >= 0 && i1 < index && index < A.length;
    }
}