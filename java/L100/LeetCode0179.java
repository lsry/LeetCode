package L100;

import java.util.Arrays;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

public class LeetCode0179 {
    public String largestNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return "0";
        }
        List<String> strs = Arrays.stream(nums).boxed().map(a -> String.valueOf(a)).sorted((sa, sb) -> {
            String s1 = sa + sb;
            String s2 = sb + sa;
            final int n = s1.length();
            for (int i = 0;i < n;++i) {
                if (s1.charAt(i) < s2.charAt(i)) {
                    return 1;
                } else if (s1.charAt(i) > s2.charAt(i)) {
                    return -1;
                }
            }
            return 1;
        }).collect(Collectors.toList());
        if (Objects.equals("0", strs.get(0))) {
            return "0";
        }
        StringBuilder res = new StringBuilder();
        for (String s : strs) {
            res.append(s);
        }
        return res.toString();
    }
}
