package L1900;

import java.util.Arrays;

public class LeetCode1996 {
    public int numberOfWeakCharacters(int[][] properties) {
        Arrays.sort(properties, (p1, p2) -> {
            return p1[0] == p2[0] ? p1[1] - p2[1] : p2[0] - p1[0];
        });
        int def = -1;
        int count = 0;
        for (int[] prop : properties) {
            if (prop[1] < def) {
                ++count;
            }
            def = Math.max(def, prop[1]);
        }
        return count;
    }
}
