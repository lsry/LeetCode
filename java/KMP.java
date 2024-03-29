import java.util.Arrays;

public class KMP{
    public int match(String str,String pattern) {
        if (pattern == null){
            return -2;
        } else if (str == null || str.length() < pattern.length()){
            return -1;
        }
        int sLen = str.length(), pLen = pattern.length();
        int[] next = new int[pLen];
        getNext(next, pattern);
        
        int i = 0,j = 0;
        while (i < sLen && j < pLen){
            if (j == -1 || str.charAt(i) == pattern.charAt(j)){
                i++;
                j++;
            } else { // 用前缀覆盖相同的后缀，然后比较下一个字符
                j = next[j];
            }
        }
        return (j == pLen) ? (i - j) : -1;
    }

    /**
     * 计算最大公共前后缀长度，不包括当前位置
     */
    public void getNext(int[] next,String pattern) {
        next[0] = -1;
        for (int i = 1;i < pattern.length();i++){
            int j = i - 1;
            while (j != 0 && pattern.charAt(i - 1) != pattern.charAt(next[j])){
                j = next[j];
            }
            next[i] = next[j] + 1;
        }
    }

    /**
     * Dragon book P87
     */
    public int[] getNext2(String pattern) {
        int[] f = new int[pattern.length()];
        int t = -1;
        f[0] = -1;
        for (int s = 0;s < pattern.length() - 1;++s) {
            while (t > -1 && pattern.charAt(s + 1) != pattern.charAt(t + 1)) {
                t = f[t];
            }
            if (pattern.charAt(s + 1) == pattern.charAt(t + 1)) {
                ++t;
                f[s + 1] = t;
            } else {
                f[s + 1] = -1;
            }
        }
        return f;
    }

    public void testNext(String pattern){
        int[] next = new int[pattern.length()];
        getNext(next, pattern);
        System.out.println(Arrays.toString(next));
    }

    public static void main(String[] args) {
        KMP kmp = new KMP();
        // 1. test next
        kmp.testNext("abaabcac");
        kmp.testNext("abcdabd");

        // 2. test match
        System.out.println(kmp.match("BBCABCDABABCDABCDABDE", "ABCDABD"));
        System.out.println(kmp.match("nnnjceiofhassssscnieo", "sscn"));
        System.out.println(kmp.match("aaaaaaaaaaaa", "aa"));
        System.out.println(kmp.match("aaaaaaaaaaaa", "aaa"));

        // 3.4.3 test next2
        System.out.println(Arrays.toString(kmp.getNext2("abababaab")));
        System.out.println(Arrays.toString(kmp.getNext2("aaaaaa")));
        System.out.println(Arrays.toString(kmp.getNext2("abbaabb")));
    }
}