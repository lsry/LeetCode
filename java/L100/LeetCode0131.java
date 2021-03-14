package L100;

import java.util.ArrayList;
import java.util.List;

public class LeetCode0131 {
    private List<List<String>> res;
    private int N;
    public List<List<String>> partition(String s) {
        res = new ArrayList<>();
        N = s.length();
        List<String> path = new ArrayList<>(N);
        trace(s, 0, path);
        return res;
    }

    private void trace(String s, int index, List<String> path) {
        if (index >= N) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = index;i < N;++i) {
            if (isPalindrome(s, index, i)) {
                path.add(s.substring(index, i + 1));
                trace(s, i + 1, path);
                path.remove(path.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
}
