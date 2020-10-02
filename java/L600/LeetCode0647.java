package L600;

public class LeetCode0647 {

    /**
     * 中心拓展求回文子串
     * 分为奇数长度和偶数长度
     */
    public int countSubstrings(String s) {
        if (s == null || s.length() <= 0){
            return 0;
        }
        int count = 0;
        for (int i = 0;i < s.length();++i) {
            count += palindromicCount(s, i, i);
            count += palindromicCount(s, i, i + 1);
        }
        return count;
    }

    private int palindromicCount(String s,int left,int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            --left;
            ++right;
            ++count;
        }
        return count;
    }

    public static void main(String[] args) {
        LeetCode0647 l647 = new LeetCode0647();
        System.out.println(l647.countSubstrings("aaa"));
        System.out.println(l647.countSubstrings("abc"));
    }
}