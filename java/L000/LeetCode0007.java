package L000;

public class LeetCode0007{

    /**
     * 将字符串翻转
     */
    public String stringReverse(String s){
        char[] array = s.toCharArray();  
        StringBuilder reverse = new StringBuilder(); 
        int i = array.length - 1;
        // 将末尾 0 消除，因为翻转过来不算整数的一部分
        while (array[i] == '0'){
            i--;
        } 
        for (; i >= 0; i--) {
            reverse.append(array[i]);  
        }   
        return reverse.toString();  
    }

    public int reverseByString(int x) {
        if (x == 0){
            return 0;
        }
        // 负数标志
        boolean isPos = false;
        String num = String.valueOf(x);
        String res = "";
        if (x < 0){
            isPos = true;
            res = stringReverse(num.substring(1));
        } else {
            res = stringReverse(num);
        }
        try {
            if (isPos){
                return Integer.valueOf("-" + res);
            } else {
                return Integer.valueOf(res);
            }
        } catch (Exception e) {
            return 0;
        }
        
    }

    public int reverse(int x) {
        if (x == Integer.MIN_VALUE) {
            return 0;
        }
        boolean flag = false;
        if (x < 0) {
            flag = true;
            x = -1 * x;
        }
        int res = 0;
        while (x != 0) {
            if (res * 10 / 10 != res) {
                return 0;
            }
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return flag ? res * -1 : res;
    }

    public static void main(String[] args) {
        LeetCode0007 code = new LeetCode0007();
        System.out.println(code.reverse(1534236469));
        System.out.println(code.reverse(37890));
        System.out.println(code.reverse(-12987));
        System.out.println(Integer.valueOf("000200"));
    }
}