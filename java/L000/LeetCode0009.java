package L000;

public class LeetCode0009 {
    public boolean isPalindromeWithStr(int x) {
        // 负数肯定不是，因为前有负号
        if (x < 0){
            return false;
        } else {
            char[] str = String.valueOf(x).toCharArray();
            int len = str.length;
            // 正数判断是否中心对称即可
            for (int i = 0;i < len/2;i++){
                if (str[i] != str[len-1-i]){
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int nx = x, px = 0;
        while (nx != 0 && px >= 0) {
            px = px * 10 + nx % 10;
            nx /= 10;
        }
        return x == px;
    }

    public static void main(String[] args) {
        LeetCode0009 l9 = new LeetCode0009();
        System.out.println("-12: " + l9.isPalindrome(-12));
        System.out.println("0: " + l9.isPalindrome(0));
        System.out.println("21: " + l9.isPalindrome(21));
        System.out.println("121: " + l9.isPalindrome(121));
        System.out.println("2147447412: " + l9.isPalindrome(2147447412));
    }
}