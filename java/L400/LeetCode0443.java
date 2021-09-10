package L400;

public class LeetCode0443 {
    public int compress(char[] chars) {
        if (chars == null || chars.length == 0) {
            return 0;
        }
        final int N = chars.length;
        int pos = 0;
        for (int low = 0, high = 0;high < N;) {
            while (high + 1 < N && chars[high + 1] == chars[high]) {
                ++high;
            }
            int cnt = high - low + 1;
            chars[pos] = chars[low];
            ++pos;
            if (cnt >1) {
                for (char c : String.valueOf(cnt).toCharArray()) {
                    chars[pos] = c;
                    ++pos;
                }
            }
            ++high;
            low = high;
        }
        return pos;
    }
}