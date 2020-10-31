package L900;

public class LeetCode0925 {
    public boolean isLongPressedName(String name, String typed) {
        int i = 0, j = 0;
        final int N = name.length(), T = typed.length();
        while (i < N && j < T) {
            if (name.charAt(i) != typed.charAt(j)) {
                return false;
            }
            if ((i < N - 1 && name.charAt(i + 1) != name.charAt(i)) || i >= N - 1) {
                ++j;
                while (j < T && typed.charAt(j) == typed.charAt(j - 1)) {
                    ++j;
                }
                ++i;
            } else {
                ++i;
                ++j;
            }
        }
        return i >= N && j >= T;
    }
}
