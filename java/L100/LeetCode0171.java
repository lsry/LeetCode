package L100;

public class LeetCode0171 {
    public int titleToNumber(String columnTitle) {
        if (columnTitle == null || columnTitle.length() == 0) {
            return 0;
        }
        final int N = columnTitle.length();
        int base = 1;
        int res = 0;
        for (int i = 1;i <= N;++i) {
            res = (columnTitle.charAt(N - i) - 'A' + 1) * base + res;
            base *= 26;
        }
        return res;
    }
}
