import java.util.HashMap;
import java.util.Map;

public class LeetCode0466 {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        if (n1 == 0) {
            return 0;
        }

        int s1cnt = 0, index = 0, s2cnt = 0;
        Map<Integer,int[]> recall = new HashMap<>();
        int[] pre_loop, in_loop;
        while (true) {
            ++s1cnt;
            for (char c : s1.toCharArray()) {
                if (c == s2.charAt(index)) {
                    index += 1;
                    if (index == s2.length()) {
                        ++s2cnt;
                        index = 0;
                    }
                }
            }
            if (s1cnt == n1) {
                return s2cnt / n2;
            }
            if (recall.containsKey(index)) {
                pre_loop = recall.get(index);
                in_loop = new int[]{s1cnt - pre_loop[0],s2cnt - pre_loop[1]};
                break;
            } else {
                recall.put(index, new int[]{s1cnt,s2cnt});
            }
        }
        int ans = pre_loop[1] + (n1 - pre_loop[0]) / in_loop[0] * in_loop[1];
        int res = (n1 - pre_loop[0]) % in_loop[0];
        for (int i = 0;i < res;++i) {
            for (char ch : s1.toCharArray()) {
                if (ch == s2.charAt(index)) {
                    ++index;
                    if (index == s2.length()) {
                        ans++;
                        index = 0;
                    }
                }
            }
        }
        return ans / n2;
    }
}