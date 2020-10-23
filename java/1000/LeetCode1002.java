import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class LeetCode1002 {
    private static final char[] chars = new char[]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
                        'p','q','r','s','t','u','v','w','x','y','z'};
    public List<String> commonChars(String[] A) {
        List<String> res = new ArrayList<>();
        if (A == null || A.length == 0) {
            return res;
        }
        int[] counts = new int[26];
        for (char c : A[0].toCharArray()) {
            counts[c - 'a']++;
        }
        int[] temp = new int[26];
        for (int i = 1;i < A.length;++i) {
            Arrays.fill(temp, 0);
            for (char c : A[i].toCharArray()) {
                temp[c - 'a']++;
            }
            for (int j = 0;j < 26;++j) {
                counts[j] = Math.min(counts[j], temp[j]);
            }
        }
        for (int i = 0;i < 26;++i) {
            for (int j = 0;j < counts[i];++j) {
                res.add(String.valueOf(chars[i]));
            }
        }
        return res;
    }
}
