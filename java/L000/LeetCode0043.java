package L000;

public class LeetCode0043 {
    /**
     * 模拟竖式乘法，从末尾起单个乘，然后将结果相加
     */
    public String multiplyStep(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")){
            return "0";
        }
        String maxStr = num1;
        String minStr = num2;
        if (num1.length() < num2.length()){
            maxStr = num2;
            minStr = num1;
        }
        String[] arr = new String[10];
        arr[1] = maxStr;
        String res = "";
        for (int i = 0;i < minStr.length();i++){
            char ch = minStr.charAt(i);
            if (ch == '0'){
                res = res + '0';
            } else {
                if (arr[ch - '0'] == null || arr[ch - '0'].length() <= 0){
                    arr[ch - '0'] = mulSingle(maxStr, ch-'0');
                }
                if (i > 0){
                    res = res + '0';
                }
                res = add(res,arr[ch-'0']);
            }
        }
        return res;
    }

    public String mulSingle(String num,int x){
        StringBuilder res = new StringBuilder();
        int carry = 0;
        for (int i = num.length() - 1;i >= 0;i--){
            int product = (num.charAt(i) - '0') * x + carry;
            res.append(product % 10);
            carry = product / 10;
        }
        if (carry > 0){
            res.append(carry);
        }
        return res.reverse().toString();
    }

    public String add(String num1,String num2){
        String maxStr = num1;
        String minStr = num2;
        if (num1.length() < num2.length()){
            maxStr = num2;
            minStr = num1;
        }
        StringBuilder res = new StringBuilder();
        int carry = 0;
        int diff = maxStr.length() - minStr.length();
        int i = maxStr.length() - 1;
        while (i - diff >= 0){
            int sum = maxStr.charAt(i) - '0' + minStr.charAt(i - diff) - '0' + carry;
            res.append(sum % 10);
            carry = sum / 10;
            i--;
        }
        while (i >= 0){
            int sum = maxStr.charAt(i) - '0' + carry;
            res.append(sum % 10);
            carry = sum / 10;
            i--;
        }
        if (carry > 0){
            res.append(carry);
        }
        return res.reverse().toString();
    }

    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")){
            return "0";
        }
        if (num1.length() > num2.length()) {
            return multiply(num2, num1);
        }
        final int mn = num1.length(), xn = num2.length();
        int[] res = new int[mn + xn];
        for (int i = mn - 1;i >= 0;--i) {
            int fac1 = num1.charAt(i) - '0';
            int fi = res.length - mn + i;
            for (int j = xn - 1;j >= 0;--j) {
                int fac2 = num2.charAt(j) - '0';
                res[fi] += fac1 * fac2;
                --fi;
            }
        }
        for (int i = res.length - 1;i > 0;--i) {
            res[i - 1] = res[i - 1] + res[i] / 10;
            res[i] = res[i] % 10;
        }
        StringBuilder rstr = new StringBuilder();
        int i = 0;
        while (i < res.length && res[i] == 0) {
            ++i;
        }
        for (;i < res.length;++i) {
            rstr.append(res[i]);
        }
        return rstr.length() == 0 ? "0" : rstr.toString();
    }

    public static void main(String[] args) {
        LeetCode0043 l43 = new LeetCode0043();
        System.out.println(l43.add("156", "244").equals("400"));
        System.out.println(l43.add("1568", "9412").equals("10980"));
        System.out.println(l43.mulSingle("423", 5).equals("2115"));
        System.out.println(l43.multiply("234", "257").equals("60138"));
        System.out.println(l43.multiply("234", "1").equals("234"));
        System.out.println(l43.multiply("234", "1000").equals("234000"));
    }
}