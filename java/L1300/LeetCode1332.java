package L1300;

public class LeetCode1332 {
    public int removePalindromeSub(String s) {
        if (s.length() == 0) {
            return 0;
        }
        boolean flag = true;
        for (int i = 0, j = s.length() - 1;i > j;++i, --j) {
            if (s.charAt(i) != s.charAt(j)) {
                flag = false;
                break;
            }
        }
        return flag ? 1 : 2;
    }
}
