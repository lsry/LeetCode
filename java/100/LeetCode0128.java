import java.util.HashSet;
import java.util.Set;

public class LeetCode0128 {
    public int longestConsecutive(int[] nums) {
        Set<Integer> si = new HashSet<>();
        for (int num : nums) {
            si.add(num);
        }
        int length = 0;
        for (int num : nums) {
            if (!si.contains(num - 1)) {
                int len = 1;
                for (int i = num + 1;si.contains(i);++i) {
                    ++len;
                }
                length = Math.max(length,len);
            }
        }
        return length;
    }
}