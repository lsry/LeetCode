package L000;

public class LeetCode0008 {

    public int myAtoiIF(String str) {
        // 消除空串情况
        if (str == null || str.length() <= 0){
            return 0;
        }
        char[] ichar = str.toCharArray();
        int index = 0;
        int len = ichar.length;
        // 跳过字符串前为空值
        while (index < len && ichar[index] == ' '){
            index++;
        }
        // 开头不是 + 、- 、0-9的字符
        if (index >= len || ichar[index] != '-' && ichar[index] != '+' && (ichar[index] < '0' || ichar[index] > '9')){
            return 0;
        }
        // 负数标志
        boolean isPos = false;
        if (index <len && ichar[index] == '-'){
            isPos = true;
        }
        // 跳过前面的正负号
        if (index < len && (ichar[index] == '-' || ichar[index] == '+')){
            index++;
        }
        // 数字的计算过程，只计算只包括 0-9 的部分当字符串末尾或者遇到非0-9结束
        int num = 0;   // num 只可能为正值
        while (index < len && ichar[index] >= '0' && ichar[index] <= '9'){
            if (num * 10 / 10 != num){ // 判断是否越界
                return isPos ? -2147483648 : 2147483647;
            }
            num = num * 10 + (ichar[index] - '0');
            // 上面这步计算后仍可能越界
            if (num < 0){
                return isPos ? -2147483648 : 2147483647;
            } else {               
                index++;
            }
        }
        return isPos ? -num : num;
    }

    /*
     * DFA
     * |--------- 0~9 ---------|
     * 0 -- +/- -- 1 -- 0~9 -- 2 <--> 0~9   
     * |           |           |
     * ----------- 3 -----------
     */

    private int state = 0;
    private int ans = 0;
    private boolean neg = false;
    private boolean lim = false;

    private void trans(char ch) {
        switch (state) {
            case 0 :
                if (ch == '+' || ch == '-') {
                    state = 1;
                    neg = ch == '-' ? true : false;
                } else if (ch >= '0' && ch <= '9') {
                    state = 2;
                    trans(ch);
                } else if (ch == ' ') {
                    state = 0;
                } else {
                    state = 3;
                }
                break;
            case 1:
                if (ch >= '0' && ch <= '9') {
                    state = 2;
                    trans(ch);
                } else {
                    state = 3;
                }
                break;
            case 2:
                if (ch >= '0' && ch <= '9') {
                    if (ans * 10 / 10 != ans) {
                        lim = true;
                        state = 3;
                    } else {
                        ans = ans * 10 + (ch - '0');
                        if (ans < 0) {
                            lim = true;
                            state = 3;
                        } else {
                            state = 2;
                        }
                    }
                } else {
                    state = 3;
                }
                break;
            default: state = 3;
        }
    }
    public int myAtoi(String str) {
        for (char c : str.toCharArray()) {
            trans(c);
        }
        if (lim) {
            ans = neg ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        } else {
           ans = neg ? -ans : ans;
        }
        return ans;
    }

    public void reset() {
        ans = 0;
        state = 0;
        neg = false;
        lim = false;
    }

    public static void main(String[] args) {
        LeetCode0008 l8 = new LeetCode0008();
        System.out.println(l8.myAtoi("42"));
        l8.reset();
        System.out.println(l8.myAtoi("   42"));
        l8.reset();
        System.out.println(l8.myAtoi("-42"));
        l8.reset();
        System.out.println(l8.myAtoi("4193 with words"));
        l8.reset();
        System.out.println(l8.myAtoi("words and 987"));
        l8.reset();
        System.out.println(l8.myAtoi("-91283472332"));
        l8.reset();
        System.out.println(l8.myAtoi("+-98"));
        l8.reset();
        System.out.println(l8.myAtoi("+") == 0);
        l8.reset();
        System.out.println(l8.myAtoi("-2147483648"));
    }
}