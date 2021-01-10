package L800;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode0830 {
    public List<List<Integer>> largeGroupPositions(String s) {
        List<List<Integer>> res = new ArrayList<>();
        final int N = s.length();
        for (int i = 0;i < N;) {
            char ch = s.charAt(i);
            int j = i;
            while (j < N && s.charAt(j) == ch) {
                ++j;
            }
            if (j - i >= 3) {
                res.add(Arrays.asList(i, j - 1));
            }
            i = j;
        }
        return res;
    }
}
