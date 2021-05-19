package L000;

import java.util.HashMap;

public class LeetCode0013 {
    /**
     * 判断可能出现的每一种情况
     * 1） CD 或 DC
     * 2） XL 或 LX
     * 3） IV 或 VI
     */
    public int romanToIntIF(String s) {
        int n = 0;
        for (int i = 0;i < s.length();i++){
            if (s.charAt(i) == 'M'){
                n += 1000;
            } else if (s.charAt(i) == 'C'){
                n += 100;
                if (i + 1 < s.length()){
                    if (s.charAt(i+1) == 'M'){
                        n += 800;
                        i++;
                    } else if (s.charAt(i+1) == 'D'){
                        n += 300;
                        i++;
                    }
                } 
            } else if (s.charAt(i) == 'X'){
                n += 10;
                if (i + 1 < s.length()){
                    if (s.charAt(i+1) == 'C'){
                        n += 80;
                        i++;
                    } else if (s.charAt(i+1) == 'L'){
                        n += 30;
                        i++;
                    } 
                } 
            } else if (s.charAt(i) == 'I'){
                n += 1;
                if (i + 1 < s.length()){
                    if (s.charAt(i+1) == 'X'){
                        n += 8;
                        i++;
                    } else if (s.charAt(i+1) == 'V'){
                        n += 3;
                        i++;
                    } 
                } 
            } else if (s.charAt(i) == 'D'){
                n += 500;
            } else if (s.charAt(i) == 'L'){
                n += 50;
            } else {
                n += 5;
            }
        }
        return n;
    }


    /**
     * 构造映射每一个数的 map，然后从左到右，如果小于右边则减，大于则加
     */
    private static final HashMap<Character,Integer> map = new HashMap<>(16);
    static {
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
    }
    public int romanToInt(String s) {
        int res = 0, LN = s.length();
        for (int i = 0;i < LN;++i) {
            int cur = map.get(s.charAt(i));
            if (i == LN - 1) {
                res += cur;
            } else if (cur < map.get(s.charAt(i + 1))) {
                res -= cur;
            } else {
                res += cur;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        LeetCode0013 l13 = new LeetCode0013();
        System.out.println("III: 3\t" + l13.romanToInt("III"));
        System.out.println("IV: 4\t" + l13.romanToInt("IV"));
        System.out.println("IX: 9\t" + l13.romanToInt("IX"));
        System.out.println("LVIII: 58\t" + l13.romanToInt("LVIII"));
        System.out.println("MCMXCIV: 1994\t" + l13.romanToInt("MCMXCIV"));
        System.out.println("MCCXLII: 1242\t" + l13.romanToInt("MCCXLII"));
    }
}