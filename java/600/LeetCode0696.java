import java.util.ArrayList;
import java.util.List;

public class LeetCode0696 {
    public int countBinarySubstringsArr(String s) {
        List<Integer> nums = new ArrayList<>();
        int count = 1;
        for (int i = 1;i < s.length();++i) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                ++count;
            } else {
                nums.add(count);
                count = 1;
            }
        }
        nums.add(count);
        int res = 0;
        for (int i = 0;i < nums.size() - 1;++i) {
            res += Math.min(nums.get(i),nums.get(i + 1));
        }
        return res;
    }

    public int countBinarySubstrings(String s) {
        int res = 0;
        int prev = 0;
        int count = 1;
        for (int i = 1;i < s.length();++i) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                ++count;
            } else {
                res += Math.min(prev, count);
                prev = count;
                count = 1;
            }
        }
        res += Math.min(prev, count);
        return res;
    }
}